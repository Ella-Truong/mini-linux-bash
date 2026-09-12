#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

using namespace std;

struct Command {
    vector<string> args;

    string inputFile;
    string outputFile;

    bool appendOutput = false;
};

Command parseCommand(const string& command);

#endif