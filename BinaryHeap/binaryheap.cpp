#include "binaryheap.h"

BinaryHeap::BinaryHeap() : capacity_(1), size_(0){
    data_ = new int[1];
    data_[0] = 0;
}

BinaryHeap::~BinaryHeap() {
    delete [] data_;
}

BinaryHeap::BinaryHeap(BinaryHeap const & heap) :
    capacity_(heap.capacity_), size_(heap.size_){
    data_ = new int[capacity_];
    for(size_t i = 0; i < size_; i++) {
        data_[i] = heap.data_[i];
    }
}

void BinaryHeap::insert(int value) {
    if(size_ == capacity_) {
        capacity_ *= 2;
        int * new_data = new int[capacity_];
        for(size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        new_data[size_] = value;
        size_++;
        delete [] data_;
        data_ = new_data;
    }
    else {
        data_[size_] = value;
        size_++;
    }
    SiftUp();
}

int BinaryHeap::extract() {
    int result = data_[0];
    data_[0] = data_[size_ - 1];
    size_--;
    SiftDown();
    return result;
}

size_t BinaryHeap::size() const {
    return size_;
}

std::ostream & operator << (std::ostream & os, BinaryHeap const & heap) {
    for(size_t i = 0; i < heap.size_; i++){
        os << heap.data_[i] << ' ';
    }
    return os;
}

void BinaryHeap::SiftUp() {
    int child_idx = size_ - 1;
    int parent_idx = (child_idx - 1) / 2;
    while(parent_idx >= 0 && data_[parent_idx] < data_[child_idx]) {
        int tmp = data_[parent_idx];
        data_[parent_idx] = data_[child_idx];
        data_[child_idx] = tmp;
        child_idx = parent_idx;
        parent_idx = (child_idx - 1) / 2;
    }
}

void BinaryHeap::SiftDown() {
    unsigned int parent_idx = 0;
    unsigned int left_child_idx = parent_idx * 2 + 1;
    unsigned int right_child_idx = parent_idx * 2 + 2;
    while(right_child_idx <= size_ - 1 && (data_[parent_idx] <
        data_[left_child_idx] || data_[parent_idx] < data_[right_child_idx])) {
        if(data_[left_child_idx] < data_[right_child_idx]) {
            int tmp = data_[parent_idx];
            data_[parent_idx] = data_[right_child_idx];
            data_[right_child_idx] = tmp;
            parent_idx = right_child_idx;
        }
        else{
            int tmp = data_[parent_idx];
            data_[parent_idx] = data_[left_child_idx];
            data_[left_child_idx] = tmp;
            parent_idx = left_child_idx;
        }
        left_child_idx = parent_idx * 2 + 1;
        right_child_idx = parent_idx * 2 + 2;
    }
    if(left_child_idx <= size_ - 1){
        if(data_[parent_idx] < data_[left_child_idx]){
            int tmp = data_[parent_idx];
            data_[parent_idx] = data_[left_child_idx];
            data_[left_child_idx] = tmp;
        }
    }
}
