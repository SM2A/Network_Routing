#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <string>

#define TOPOLOGY "topology"

class CommandParser {

private:

    static CommandParser *instance;

    CommandParser() {

    }

    void parseTopology(std::string data);

public:

    static CommandParser *getInstance();

    void parse(std::string command);

};

#endif