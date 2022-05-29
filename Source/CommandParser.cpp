#include "CommandParser.h"
#include <sstream>

#define SEPARATOR ' '
#define DELIMITER '-'

using namespace std;

CommandParser *CommandParser::instance = nullptr;

CommandParser *CommandParser::getInstance() {
    if (instance == nullptr) instance = new CommandParser();
    return instance;
}

void CommandParser::parse(const string &command) {

    string cmd;
    stringstream stream(command);
    getline(stream, cmd, SEPARATOR);

    if (cmd == TOPOLOGY) parseTopology(stream.str());
    else if (cmd == MODIFY) parseModify(stream.str());
    else if (cmd == REMOVE) parseRemove(stream.str());
    else if (cmd == SHOW);
    else if (cmd == LSRP);
    else if (cmd == DVRP);
}

void CommandParser::parseTopology(const string &data) {

    string value, temp;
    stringstream stream(data);
    getline(stream, temp, SEPARATOR);

    while (getline(stream, value, SEPARATOR)) {
        stringstream entry(value);
        string source, destination, cost;

        getline(entry, source, DELIMITER);
        getline(entry, destination, DELIMITER);
        getline(entry, cost, DELIMITER);

        network->addLink(stoi(source), stoi(destination), stoi(cost));
    }
}

void CommandParser::parseModify(const string &data) {

    string value, temp;
    stringstream stream(data);
    getline(stream, temp, SEPARATOR);

    string source, destination, cost;

    getline(stream, source, DELIMITER);
    getline(stream, destination, DELIMITER);
    getline(stream, cost, DELIMITER);

    network->modifyLink(stoi(source), stoi(destination), stoi(cost));
}

void CommandParser::parseRemove(const string &data) {

    string value, temp;
    stringstream stream(data);
    getline(stream, temp, SEPARATOR);

    string source, destination;

    getline(stream, source, DELIMITER);
    getline(stream, destination, DELIMITER);

    network->removeLink(stoi(source), stoi(destination));
}
