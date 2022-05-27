#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Node.h"

class Network{

private:

    std::vector<Node> nodes;
    std::vector<std::vector<int>> links;

public:

    void show();

    void addLink(int source, int destination, int cost);
    void modifyLink(int source, int destination, int cost);
    void removeLink(int source, int destination);

    void LSRP();

    void LSRP(int node);
    void DVRP();
    void DVRP(int node);

};

#endif
