#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <cstdlib>
#include <iostream>

class Binary_Heap {
public:
    Binary_Heap();
    Binary_Heap(Binary_Heap const&);
    void insert(int);
    int extract();
    size_t size() const;
    friend std::ostream & operator << (std::ostream &, Binary_Heap const &);
    ~Binary_Heap();

private:
    size_t memory_size_;
    size_t size_;
    int *data_;
    void sift_up();
    void sift_down();

};

#endif // BINARYHEAP_H
