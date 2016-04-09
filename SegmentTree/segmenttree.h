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
    int min(int lPoint, int rPoint) const;

private:
    std::vector<int> tree_;

private:
    minRec(int lPoint, int rPoint, int l, int r) const;
    int neighbour(int arg) const;
    int parent(int arg) const;
};

#endif // SEGMENTTREE_H
