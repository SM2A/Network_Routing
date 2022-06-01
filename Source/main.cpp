#include <iostream>
#include "Network.h"
#include "CommandParser.h"

#include <sstream>

using namespace std;

int main() {

    stringstream stream("topology 1-2-19\n"
                        "topology 1-3-9\n"
                        "topology 2-4-3\n"
                        "show\n"
                        "dvrp 1");

    string input;
    while (getline(stream, input)) CommandParser::getInstance()->parse(input);
//    while (getline(cin, input)) CommandParser::getInstance()->parse(input);

    return 0;
}
