#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <cstdlib>
#include <iostream>

class BinaryHeap {
public:
    BinaryHeap();
    BinaryHeap(BinaryHeap const &);
    ~BinaryHeap();

    void insert(const int &);
    int extract();
    size_t size() const;
    friend std::ostream & operator << (std::ostream &, BinaryHeap const &);

private:
    size_t capacity_;
    size_t size_;
    int *data_;
    void SiftUp();
    void SiftDown();

};

#endif // BINARYHEAP_H
