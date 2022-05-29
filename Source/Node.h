#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {

private:

    int num;

    std::vector<int> distance;
    std::vector<int> prev;
    std::vector<int> parent;

public:

    Node(int num) : num(num) {}

    int getNum() const {
        return  num;
    }
};

#endif
