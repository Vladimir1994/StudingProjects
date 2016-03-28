#ifndef SMALLALLOCATOR_H
#define SMALLALLOCATOR_H

#include <cstdlib>

class SmallAllocator
{
public:
    void * Alloc(unsigned int size);
    void * ReAlloc(void *pointer, unsigned int size);
    void Free(void *pointer);

private:
    const static unsigned int memLimit_ = 1024;
    const static unsigned int bytesInAddress_ = 3;
    unsigned int memControlTableSize_ = 0;

    unsigned char Memory_[memLimit_];

private:
    bool getMcb(unsigned int mctLine,
                unsigned int &bytesAlloced,
                unsigned int &mcbPosition);
    bool setMcb(unsigned int mcbPosition, unsigned int bytesAlloced);
    bool deleteMcb(unsigned int mctLine);

    void IntToBytes(unsigned int num, unsigned char bytes[bytesInAddress_]);
    void BytesToInt(unsigned int &num, const unsigned char bytes[bytesInAddress_]);
};

#endif // SMALLALLOCATOR_H
