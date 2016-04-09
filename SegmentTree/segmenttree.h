#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>

#include <algorithm>
#include <math.h>

class SegmentTree
{
public:
    SegmentTree(const std::vector<int> &tree);
    ~SegmentTree() {}
    void set(int idx, int val);
    int min(int lPoint, int rPoint);

private:
    std::vector<int> tree_;

private:
    minRec(int lPoint, int rPoint, int l, int r);
    int neighbour(int arg);
    int parent(int arg);
};

#endif // SEGMENTTREE_H
