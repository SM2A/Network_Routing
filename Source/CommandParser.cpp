#include "CommandParser.h"
#include <sstream>
#include "Network.h"

#define SEPARATOR ' '
#define DELIMITER '-'

using namespace std;

CommandParser *CommandParser::instance = nullptr;

CommandParser *CommandParser::getInstance() {
    if (instance == nullptr) instance = new CommandParser();
    return instance;
}

void CommandParser::parse(string command) {

    string cmd;
    stringstream stream(command);
    getline(stream, cmd, SEPARATOR);

    if (cmd == TOPOLOGY) parseTopology(stream.str());
}

void CommandParser::parseTopology(string data) {

    string value, temp;
    stringstream stream(data);
    getline(stream, temp, SEPARATOR);

    while (getline(stream, value, SEPARATOR)) {
        stringstream entry(value);
        string source, destination, cost;

        getline(entry, source, DELIMITER);
        getline(entry, destination, DELIMITER);
        getline(entry, cost, DELIMITER);

        Network::getInstance()->addLink(stoi(source), stoi(destination), stoi(cost));
    }
}
