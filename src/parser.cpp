#include "parser.hpp"
#include <sstream>

using namespace std;

vector<string> parseCommand(const string& command) {
    vector<string> args;
    stringstream ss(command);

    string word;
    
    while(ss >> word) {
        args.push_back(word);
    }

    return args;

}