#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Node.h"

class Network {

private:

    static Network *instance;

    std::vector<Node *> nodes;
    std::vector<std::vector<int>> links;
    std::vector<std::vector<int>> algorithmsLinks;

    Network() {

    }

    Node* findNode(int num);
    void copyLinks();
    void dijkstra(int src);

public:

    static Network *getInstance();

    void show();

    void addLink(int source, int destination, int cost);
    void modifyLink(int source, int destination, int cost);
    void removeLink(int source, int destination);

    void lsrp();
    void lsrp(int src);

    void dvrp();
    void dvrp(int src);

};

#endif
