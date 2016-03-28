#include "sortings.h"

#include <algorithm>

void qsort(vector<int> &v, long l, long r)
{
    if(l >= r)
        return;

    long l_ptr = l - 1;
    long r_ptr = r;
    int pivot = v.at(r_ptr);
    for (;;) {
        while (v.at(++l_ptr) < pivot)
            while (v.at(--r_ptr) > pivot)
                if (l_ptr == r_ptr)
                    break;
        if (l_ptr >= r_ptr)
            break;
        swap(v.at(l_ptr), v.at(r_ptr));
    }
    swap(v.at(l_ptr), v.at(r));

    qsort(v, l, l_ptr - 1);
    qsort(v, l_ptr + 1, r);
}

void merge(vector<int> &v, int l, int r, int m);

void mergesort(vector<int> &v, int l, int r)
{
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, r ,m);
    }
    return;
}

void SiftDown(vector<int> &heap, int start_element);

void heapsort(vector<int> &v, int l, int r)
{
    vector<int> heap(r - l + 1);
    copy(v.begin() + l, v.begin() + r + 1, heap.begin());

    for (int i = heap.size() / 2; i >= 0; i--)
        SiftDown(heap, i);

    int cnt = 0;
    while (heap.size() > 0) {
        swap(heap[0], heap[heap.size() - 1]);
        v[l + cnt] = heap[heap.size() - 1];
        heap.pop_back();
        if (heap.size() > 0)
            SiftDown(heap, 0);
        cnt ++;
    }
}

void merge(vector<int> &v, int l, int r, int m)
{
    int i = l;
    int k = 0;
    int j = m + 1;
    vector<int> tmp(v.size());
    while (i <= m && j <= r) {
        if (v.at(i) <= v.at(j)) {
            tmp[k] = v.at(i);
            k++;
            i++;
        } else {
            tmp[k] = v.at(j);
            k++;
            j++;
        }
    }
    while (i <= m) {
        tmp[k] = v.at(i);
        k++;
        i++;
    }
    while (j <= r) {
        tmp[k] = v.at(j);
        k++;
        j++;
    }
    for (i = l; i < k + l; i++)
        v.at(i) = tmp[i - l];
}

void SiftDown(vector<int> &heap, int start_element)
{
    int parent = start_element;
    size_t child_1 = parent * 2 + 1;
    size_t child_2 = parent * 2 + 2;
    while (child_2 <= heap.size() - 1) {
        if (heap.at(parent) > heap.at(child_1)
                || heap.at(parent) > heap.at(child_2)) {
            if (heap.at(child_1) > heap.at(child_2)) {
                swap(heap.at(child_2), heap.at(parent));
                parent = child_2;
            } else {
                swap(heap.at(child_1), heap.at(parent));
                parent = child_1;
            }
            child_1 = parent * 2 + 1;
            child_2 = parent * 2 + 2;
        } else {
            break;
        }
    }
    if (child_1 <= heap.size() - 1 ) {
        if (heap.at(parent) > heap.at(child_1))
            swap(heap.at(child_1), heap.at(parent));
    }
}
