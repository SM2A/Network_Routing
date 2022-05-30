#include "Network.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

#define INF 99999
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

    for (int i = 0; i < links.size(); ++i) cout << left << setw(NUM_WIDTH) << setfill(SEPARATOR) << i + 1;
    cout << endl;

    for (int i = 0; i < ((links.size() * NUM_WIDTH) + NUM_WIDTH); ++i) cout << '_';
    cout << endl;

    for (int i = 0; i < links.size(); ++i) {
        cout << left << setw(NUM_WIDTH) << setfill(SEPARATOR) << i + 1 << '|';
        for (int j : links[i]) cout << left << setw(NUM_WIDTH) << setfill(SEPARATOR) << j;
        cout << endl;
    }
}

void Network::addLink(int source, int destination, int cost) {

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

    if (findNode(source) == nullptr) nodes.push_back(new Node(source));
    if (findNode(destination) == nullptr) nodes.push_back(new Node(destination));
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
    source -= 1;
    destination -= 1;

    links[source][destination] = NO_LINK;
    links[destination][source] = NO_LINK;
}

void Network::lsrp() {
    copyLinks();
    for (int i = 0; i < links.size(); ++i) {
        cout << "Node " << i << ":" << endl;
        dijkstra(i);
    }
}

void Network::lsrp(int src) {
    copyLinks();
    dijkstra(src - 1);
}

void Network::dvrp() {

}

void Network::dvrp(int src) {

}

Node *Network::findNode(int num) {
    auto iter = find_if(nodes.begin(), nodes.end(), [num](Node *node) -> bool { return node->num == num; });
    if (iter != nodes.end()) return iter[0];
    else return nullptr;
}

void recvPrintPath(vector<int> prev, int visited) {
    if (prev[visited] == -1) return;
    recvPrintPath(prev, prev[visited]);
    cout << "->" << visited + 1;
}

void Network::dijkstra(int src) {

    Node *node = findNode(src);
    node->initNode(links.size());
    node->distance[src] = 0;

    vector<int> visited;
    for (int j = 0; j < links.size(); ++j) visited.push_back(0);

    for (int j = 0; j < links.size() - 1; j++) {

        int min = INF, i, u;

        for (i = 0; i < links.size(); i++) {
            if (visited[i] == 0 && node->distance[i] <= min) {
                min = node->distance[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < links.size(); v++) {
            if (algorithmsLinks[u][v] > 0 && node->distance[u] != INF) {
                int alt = node->distance[u] + algorithmsLinks[u][v];
                if (alt < node->distance[v]) {
                    node->distance[v] = alt;
                    node->prev[v] = u;
                }
            }
        }

        cout << "Iter " << j + 1 << ":" << endl;

        cout << left << setw(NUM_WIDTH * 2) << setfill(SEPARATOR) << "Dest";

        for (int k = 0; k < links.size(); k++) cout << left << setw(NUM_WIDTH * 2) << setfill(SEPARATOR) << k + 1;
        cout << endl;

        for (int k = 0; k < (links.size() * (NUM_WIDTH * 2) + NUM_WIDTH); ++k) cout << '_';
        cout << endl;

        cout << left << setw(NUM_WIDTH * 2) << setfill(SEPARATOR) << "Cost";

        for (int k = 0; k < links.size(); k++) {
            if (node->distance[k] == INF) cout << left << setw(NUM_WIDTH * 2) << setfill(SEPARATOR) << NO_LINK;
            else cout << left << setw(NUM_WIDTH * 2) << setfill(SEPARATOR) << node->distance[k];
        }
        cout << endl;

        for (int k = 0; k < (links.size() * (NUM_WIDTH * 2) + NUM_WIDTH); ++k) cout << '_';
        cout << endl << endl;


    }

    cout << "Path: [s]->[d]   Min-Cost   Shortest Path" << endl;
    cout << "      ---------  ---------  --------------" << endl;
    for (int k = 0; k < links.size(); k++) {
        if (k == src) continue;

        cout << "       " << "[" << src + 1 << "]"
             << "->" << "[" << k + 1 << "]   "
             << node->distance[k] << "        "
             << src + 1;

        recvPrintPath(node->prev, k);
        cout << endl;
    }

    cout << endl;

    node->clearNode();
}


void Network::copyLinks() {

    algorithmsLinks.clear();

    for (int i = 0; i < links.size(); ++i) {
        algorithmsLinks.push_back(vector<int>());
        for (int j = 0; j < links[i].size(); ++j) {
            algorithmsLinks[i].push_back(links[i][j]);
            if (links[i][j] == -1) algorithmsLinks[i][j] = INF;
        }
    }
}
