#include "Node.h"

#define INF 99999
#define NO_LINK -1
#define SAME_NODE 0

void Node::initNode(int count) {
    for (int i = 0; i <count ; ++i) {
        prev.push_back(NO_LINK);
        distance.push_back(INF);
    }
}

void Node::clearNode() {
    prev.clear();
    parent.clear();
    distance.clear();
}
