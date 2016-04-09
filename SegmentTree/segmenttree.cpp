#include "segmenttree.h"

SegmentTree::SegmentTree(const std::vector<int> &tree)
{
    tree_.resize(tree.size());
    for (int i = tree.size() - 1; i > 0; i-=2) {
        tree_.at((i + 1) / 2 - 1) = std::min(tree.at(i),
                                              tree.at(i - 1));
    }
}

void SegmentTree::set(int idx, int val)
{
    int targetIndex = idx + tree_.size() / 2;
    tree_.at(targetIndex) = val;
    int neighbourIndex = neighbour(targetIndex);
    int parentIndex = parent(targetIndex);
    while (targetIndex > 0) {
        int min_child = std::min(tree_.at(targetIndex),
                                 tree_.at(neighbourIndex));
        if (tree_.at(parentIndex) == min_child)
            break;
        tree_.at(parentIndex) = min_child;
        targetIndex = parentIndex;
        neighbourIndex = neighbour(targetIndex);
        parentIndex = parent(targetIndex);
    }
}

int SegmentTree::min(int lPoint, int rPoint) const
{
    return minRec(lPoint, rPoint, 0, tree_.size() / 2);
}

int SegmentTree::minRec(int lPoint, int rPoint, int l, int r) const
{
    int size = tree_.size() / 2;
    if (lPoint == rPoint)
        return tree_.at(size + rPoint);

    if (lPoint == l && rPoint == r) {
        return tree_.at(round((((float)size + 1)
                               + (float)l - 1) / ((float)r
                                                  - (float)l + 1)) - 1);
    }
    else if (lPoint < (l + r) / 2 && rPoint <= (l + r) / 2) {
        return minRec(lPoint, rPoint, l, (l + r) / 2);
    }
    else if (lPoint >= (l + r) / 2 + 1 && rPoint > (l + r) / 2) {
        return minRec(lPoint, rPoint, (l + r) / 2 + 1, r);
    }

    return std::min(minRec(lPoint, (l + r) / 2, l, (l + r) / 2),
                    minRec((l + r) / 2 + 1, rPoint, (l + r) / 2 + 1, r));
}

int SegmentTree::neighbour(int arg) const
{
    if (arg % 2 == 0)
        return --arg;
    else
        return ++arg;
}

int SegmentTree::parent(int arg) const
{
    return (arg - 1) / 2;
}

