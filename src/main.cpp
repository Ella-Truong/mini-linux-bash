#include <iostream>
#include <string>
#include <vector>

#include "parser.hpp"
#include "builtin.hpp"
#include "executor.hpp"
#include "prompt.hpp"

using namespace std;

int main(){
    string command;

    while(true){
        //show shell prompt
        displayPrompt();

        //read user input
        getline(cin, command);

        //exit shell if user user types "exit"
        if (command == "exit") {
            break;
        }

        //parse the command
        Command parsedCommand = parseCommand(command);

        //skip empty commands
        if (parsedCommand.args.empty()) {
            continue;
        }
        
        //handle built-in commands
        if (handleBuiltin(parsedCommand.args)) {
            continue;
        }

        //execute external commands
        executeExternalCommand(parsedCommand);
    }

    return 0;
}
 