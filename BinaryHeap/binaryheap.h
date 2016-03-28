#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <cstdlib>
#include <iostream>

class BinaryHeap
{
public:
    BinaryHeap();
    BinaryHeap(BinaryHeap const &heap);
    ~BinaryHeap();

    void insert(int value);
    int extract();
    size_t size() const;
    friend std::ostream & operator << (std::ostream &os,
                                       BinaryHeap const &heap);

private:
    size_t capacity_;
    size_t size_;
    int *data_;

private:
    void SiftUp();
    void SiftDown();

};

#endif // BINARYHEAP_H
