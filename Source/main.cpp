#include <iostream>
#include "Network.h"
#include "CommandParser.h"

using namespace std;

int main() {

    Network *network = Network::getInstance();

    /*network->addLink(1, 4, 2);
    network->addLink(11, 12, 5);
    network->modifyLink(4, 1, 9);*/

    string input;
    while (getline(cin, input)){
        CommandParser::getInstance()->parse(input);
    }

    network->show();

    return 0;
}
