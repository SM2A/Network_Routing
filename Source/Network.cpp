#include "Network.h"
#include <iostream>
#include <iomanip>

#define NO_LINK -1
#define SAME_NODE 0
#define NUM_WIDTH 5
#define SEPARATOR ' '
#define SAME_NODE_ERROR "Source and Destination cannot be the same"

using namespace std;

Network *Network::instance = nullptr;

Network *Network::getInstance() {
    if (instance == nullptr) instance = new Network();
    return instance;
}

void Network::show() {

    cout << left << setw(NUM_WIDTH) << setfill(SEPARATOR) << "      ";

    for (int i = 0; i < links.size(); ++i) cout << left << setw(NUM_WIDTH) << setfill(SEPARATOR) << i;
    cout << endl;

    for (int i = 0; i < ((links.size() * NUM_WIDTH) + NUM_WIDTH); ++i) cout <<'_';
    cout << endl;

    for (int i = 0; i < links.size(); ++i) {
        cout << left << setw(NUM_WIDTH) << setfill(SEPARATOR) << i << '|';
        for (int j : links[i]) cout << left << setw(NUM_WIDTH) << setfill(SEPARATOR) << j;
        cout << endl;
    }
}

void Network::addLink(int source, int destination, int cost) {

    // TODO add new node to node list

    if (source == destination) {
        cerr << SAME_NODE_ERROR << endl;
        return;
    }

    for (int i = 0; links.size() < max(source, destination); ++i) {
        vector<int> row;
        for (int j = 0; row.size() < max(source, destination); ++j) row.push_back(NO_LINK);
        links.push_back(row);
    }

    for (auto &link : links) for (int j = 0; link.size() < max(source, destination); ++j) link.push_back(NO_LINK);

    for (int i = 0; i < links.size(); ++i) links[i][i] = SAME_NODE;

    source -= 1;
    destination -= 1;

    links[source][destination] = cost;
    links[destination][source] = cost;
}

void Network::modifyLink(int source, int destination, int cost) {

    if (source == destination) {
        cerr << SAME_NODE_ERROR << endl;
        return;
    }

    source -= 1;
    destination -= 1;

    links[source][destination] = cost;
    links[destination][source] = cost;
}

void Network::removeLink(int source, int destination) {

}

void Network::LSRP() {

}

void Network::LSRP(int node) {

}

void Network::DVRP() {

}

void Network::DVRP(int node) {

}
