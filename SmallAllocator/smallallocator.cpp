#include "smallallocator.h"
#include <iostream>
#include <algorithm>

using namespace std;

void * SmallAllocator::Alloc(unsigned int size) {
    unsigned int mctLinesCount = memControlTableSize_ / bytesInAddress_;
    if(mctLinesCount == 0) {
        setMCB(0, size);
        return &Memory_[bytesInAddress_];
    }

    bool isFirstFree = true;

    for(unsigned int i = 0; i < mctLinesCount; i++) {
        unsigned int mcbPosition;
        unsigned int bytesAlloced;

        getMCB(i, bytesAlloced, mcbPosition);
        if(mcbPosition == 0) {
            isFirstFree = false;
            break;
        }
    }

    unsigned int mcbPositionMin = memLimit_;

    if(isFirstFree) {
        for(unsigned int i = 0; i < mctLinesCount; i++) {
            unsigned int mcbPosition;
            unsigned int bytesAlloced;
            getMCB(i, bytesAlloced, mcbPosition);
            if(mcbPosition < mcbPositionMin) {
                mcbPositionMin = mcbPosition;
            }
        }
    }

    if(isFirstFree && size + bytesInAddress_ < mcbPositionMin) {
        setMCB(0, size);
        return &Memory_[bytesInAddress_];
    }

    for(unsigned int i = 0; i < mctLinesCount - 1; i++) {
        unsigned int mcbPosition;
        unsigned int bytesAlloced;
        getMCB(i, bytesAlloced, mcbPosition);
        unsigned int mcbPositionNext = memLimit_;
        for(unsigned int i = 0; i < mctLinesCount - 1; i++) {
            unsigned int mcbPositionProbablyNext;
            unsigned int bytesAllocedProbablyNext;
            getMCB(i + 1, mcbPositionProbablyNext, bytesAllocedProbablyNext);
            if(mcbPositionProbablyNext - mcbPosition > 0 &&
                mcbPositionProbablyNext - mcbPosition <
                mcbPositionNext - mcbPosition &&
                mcbPositionProbablyNext - mcbPosition != 0) {
                mcbPositionNext = mcbPositionProbablyNext;
            }
        }
        if(mcbPositionNext - mcbPosition - bytesAlloced > size + bytesInAddress_) {
            setMCB(mcbPosition + bytesAlloced + 1, size);
            return &Memory_[mcbPosition + bytesAlloced + bytesInAddress_];
        }
    }

    unsigned int mcbPositionLast;
    unsigned int bytesAllocedLast;
    getMCB(mctLinesCount - 1, mcbPositionLast, bytesAllocedLast);
    setMCB(mcbPositionLast + bytesAllocedLast + bytesInAddress_, size);
    return &Memory_[mcbPositionLast + bytesAllocedLast + 2 * bytesInAddress_];
}

void * SmallAllocator::ReAlloc(void * pointer, unsigned int size) {
    unsigned char mcb[bytesInAddress_];
    memcpy(mcb, &Memory_[(intptr_t)pointer - (intptr_t)&Memory_[0]
        - bytesInAddress_], bytesInAddress_);
    unsigned int bytesAlloced;
    BytesToInt(bytesAlloced, mcb);

    if(bytesAlloced > size) {
        unsigned char mcbNew[bytesInAddress_];
        IntToBytes(size, mcbNew);
        memcpy(&Memory_[(intptr_t)pointer - (intptr_t)&Memory_[0]
                - bytesInAddress_], mcbNew, bytesInAddress_);
        return pointer;
    }

    void * ptr = Alloc(size);
    memcpy(ptr, pointer, min(bytesAlloced, size));
    Free(pointer);
    return ptr;
}

void SmallAllocator::Free(void * pointer) {
    unsigned int mctLinesCount = memControlTableSize_ / bytesInAddress_;

    unsigned int mcbPosition;
    unsigned int bytesAlloced;
    for(unsigned int i = 0; i < mctLinesCount - 1; i++) {
        getMCB(i, bytesAlloced, mcbPosition);

        if((unsigned int)((intptr_t)pointer - (intptr_t)&Memory_[0])
            == mcbPosition + bytesInAddress_) {
            deleteMCB(i);
            return;
        }
    }
}

bool SmallAllocator::getMCB(unsigned int mctLine, unsigned int & bytesAlloced,
    unsigned int & mcbPosition) {

    if((mctLine + 1) * bytesInAddress_ - 1 > memControlTableSize_)
        return false;


    unsigned char mctLineBytes[bytesInAddress_];
    memcpy(mctLineBytes, &Memory_[memLimit_ - (mctLine + 1) *
        bytesInAddress_ ], bytesInAddress_);

    BytesToInt(mcbPosition, mctLineBytes);
    unsigned char mcb[bytesInAddress_];
    memcpy(mcb, &Memory_[mcbPosition], bytesInAddress_);

    BytesToInt(bytesAlloced, mcb);

    return true;
}

bool SmallAllocator::setMCB(unsigned int mcbPosition, unsigned int bytesAlloced) {
    if(mcbPosition > memLimit_ - bytesInAddress_ - memControlTableSize_ + 1)
        return false;

    unsigned char mctLineBytes[bytesInAddress_];
    IntToBytes(mcbPosition, mctLineBytes);
    memcpy(&Memory_[memLimit_  - bytesInAddress_
        - memControlTableSize_], mctLineBytes, bytesInAddress_);
    memControlTableSize_ += bytesInAddress_;

    unsigned char mcb[bytesInAddress_];
    IntToBytes(bytesAlloced, mcb);
    memcpy(&Memory_[mcbPosition], mcb, bytesInAddress_);

    return true;
}

bool SmallAllocator::deleteMCB(unsigned int mctLine) {
    if((mctLine + 1) * bytesInAddress_ - 1 > memControlTableSize_)
        return false;

    memcpy(&Memory_[memLimit_ - memControlTableSize_ + bytesInAddress_],
        &Memory_[memLimit_ - memControlTableSize_],
        memControlTableSize_ - (mctLine + 1)  * bytesInAddress_);
    memControlTableSize_ -= bytesInAddress_;
    return true;
}

void SmallAllocator::IntToBytes(unsigned int num,
    unsigned char bytes[bytesInAddress_]) {

    for (unsigned int i = 0; i < bytesInAddress_; i++)
        bytes[bytesInAddress_ - i - 1] = (num >> (i * 8));
}

void SmallAllocator::BytesToInt(unsigned int & num,
    const unsigned char bytes[bytesInAddress_]) {

    num = 0;
    for (unsigned int i = 0; i < bytesInAddress_; i++)
          num = (num << 8) + bytes[i];
}
