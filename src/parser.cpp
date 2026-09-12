#include "parser.hpp"
#include <sstream>

using namespace std;


Command parseCommand(const string& command) {
    Command result;

    stringstream ss(command);
    string word;
    
    while(ss >> word) {
        if (word == ">") {
            result.appendOutput = false;
            ss >> result.outputFile;

        }else if(word == ">>") {
            result.appendOutput = true;
            ss >> result.outputFile;

        }else if(word == "<") {
            ss >> result.inputFile;

        }else{
            result.args.push_back(word);
        }
    }

    return result;
}