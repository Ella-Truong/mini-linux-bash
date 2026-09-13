#include "parser.hpp"
#include <sstream>

using namespace std;


Command parseCommand(const string& command) {
    Command result;
    
    //create a stream that reads tokens from the command string
    stringstream ss(command);
    string word;

    //example: command = "ls > text.txt"
    //read one whitespace-separated token at a time
    while(ss >> word) {
        //when ss read to ">" token, meaning redirect stdout to a file
        if (word == ">") {
            result.appendOutput = false;
            
            //read the next token ("text.txt") from the stream
            //and store it in output filename --> result.outputFile = "text.txt"
            ss >> result.outputFile;
        
        //">>" means redirect stdout and append to the file
        }else if(word == ">>") {
            result.appendOutput = true;
            ss >> result.outputFile;
        
        //"<" mean read stdin from a file
        }else if(word == "<") {
            //ex: cat < input.txt
            //read the next token as the input filename
            ss >> result.inputFile;

        }else{
            //any other token is treaded as a normal command argument
            result.args.push_back(word);
        }
    }

    return result;
}