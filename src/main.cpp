#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>    //provide pid_t = process(p_) ID(_id) type(_t), a datatype used for process IDs in Linux 
#include <sys/wait.h>
#include <cstdlib>
#include "parser.hpp"
#include "builtin.hpp"

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

        if (handleBuiltin(args)) {
            continue;
        }

        //if not, create a child process
        pid_t id = fork();    //fork() return process ID type

        if (id < 0) {
            //fork failed
            cout << "Failed to create process" << endl;

        }else if(id==0){
            //convert vector<string> to vector<char*> for execvp()
            vector<char*> argv;

            for (string& arg: args) {
                argv.push_back(arg.data());
            }

            //execvp() needs NULL at the end
            argv.push_back(nullptr);

            //execute the command
            execvp(argv[0], argv.data());

            //runs only if conmmand fails
            perror("execvp");
            exit(1);

        }else{
            //present waits for child
            wait(NULL);
        }
    }

    return 0;
}
 