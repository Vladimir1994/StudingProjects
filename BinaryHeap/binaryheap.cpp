#include "binaryheap.h"

void Binary_Heap::sift_up() {
    int child_idx = size_ - 1;
    int parent_idx = (child_idx - 1)/2;
    while(parent_idx >= 0 && data_[parent_idx] < data_[child_idx]) {
        int tmp = data_[parent_idx];
        data_[parent_idx] = data_[child_idx];
        data_[child_idx] = tmp;
        child_idx = parent_idx;
        parent_idx = (child_idx - 1)/2;
    }
}

void Binary_Heap::sift_down() {
    unsigned int parent_idx = 0;
    unsigned int left_child_idx = parent_idx*2 + 1;
    unsigned int right_child_idx = parent_idx*2 + 2;
    while(right_child_idx <= size_ - 1 && (data_[parent_idx] < data_[left_child_idx] || data_[parent_idx] < data_[right_child_idx])) {
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
        left_child_idx = parent_idx*2 + 1;
        right_child_idx = parent_idx*2 + 2;
    }
    if(left_child_idx <= size_ - 1){
        if(data_[parent_idx] < data_[left_child_idx]){
            int tmp = data_[parent_idx];
            data_[parent_idx] = data_[left_child_idx];
            data_[left_child_idx] = tmp;
        }
    }
}

Binary_Heap::Binary_Heap() : memory_size_(1), size_(0){
    data_ = new int[1];
    data_[0] = 0;
}

Binary_Heap::Binary_Heap(Binary_Heap const& heap) : memory_size_(heap.memory_size_), size_(heap.size_){
    data_ = new int[memory_size_];
    for(size_t i = 0; i < size_; i++) {
        data_[i] = heap.data_[i];
    }
}

void Binary_Heap::insert(int value) {
    if(size_ == memory_size_) {
        memory_size_ *= 2;
        int * new_data = new int[memory_size_];
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
    sift_up();
}

int Binary_Heap::extract() {
    int result = data_[0];
    data_[0] = data_[size_ - 1];
    size_--;
    sift_down();
    return result;
}

size_t Binary_Heap::size() const {
    return size_;
}

std::ostream & operator << (std::ostream & os, Binary_Heap const & heap) {
    for(size_t i = 0; i < heap.size_; i++){
        os << heap.data_[i] << ' ';
    }
    return os;
}

Binary_Heap::~Binary_Heap() {
    delete [] data_;
}
