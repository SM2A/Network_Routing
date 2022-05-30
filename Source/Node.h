#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {

private:

public:

    int num;

    std::vector<int> distance;
    std::vector<int> prev;
    std::vector<int> parent;

    Node(int num) : num(num) {}

    void initNode(int count);
    void clearNode();
};

#endif
