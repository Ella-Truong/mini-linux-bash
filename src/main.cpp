#include <iostream>
#include <string>
#include <vector>

#include "parser.hpp"
#include "builtin.hpp"
#include "executor.hpp"

using namespace std;

int main(){
    string command;

    while(true){
        //show shell prompt
        cout << "mini-shell> ";

        //read user input
        getline(cin, command);

        //exit shell if user user types "exit"
        if (command == "exit") {
            break;
        }

        //parse the command
        vector<string> args = parseCommand(command);

        //skip empty commands
        if (args.empty()) {
            continue;
        }
        
        //handle built-in commands
        if (handleBuiltin(args)) {
            continue;
        }

        //execute external commands
        executeExternalCommand(args);
        
    }

    return 0;
}
 