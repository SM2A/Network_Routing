#include "Network.h"
#include <iostream>

#define SAME_ERROR "Source and Destination cannot be the same"

using namespace std;

Network *Network::instance = nullptr;

Network *Network::getInstance() {
    if (instance == nullptr) instance = new Network();
    return instance;
}

void Network::show() {
    for (auto &i : links) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Network::addLink(int source, int destination, int cost) {

    if (source == destination) {
        cerr << SAME_ERROR << endl;
        return;
    }

    for (int i = 0; links.size() < max(source, destination); ++i) {
        vector<int> row;
        for (int j = 0; row.size() < max(source, destination); ++j) row.push_back(-1);
        links.push_back(row);
    }

    for (auto &link : links) for (int j = 0; link.size() < max(source, destination); ++j) link.push_back(-1);

    source -= 1;
    destination -= 1;

    links[source][destination] = cost;
    links[destination][source] = cost;
}

void Network::modifyLink(int source, int destination, int cost) {

    if (source == destination) {
        cerr << SAME_ERROR << endl;
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
