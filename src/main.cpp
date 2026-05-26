#include <iostream>
#include <string>
#include <unistd.h>    //provide pid_t = process(p_) ID(_id) type(_t), a datatype used for process IDs in Linux 
#include <sys/wait.h>

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

        //if not, create a child process
        pid_t id = fork();    //fork() return process ID type

        if(id==0){
            //child process executes command
            execlp(command.c_str(), command.c_str(), NULL);

            //runs only if conmmand fails
            cout << "Command not found" << endl;
            exit(1);

        }else{
            //present waits for child
            wait(NULL);
        }
    }

    return 0;
}
 