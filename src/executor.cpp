#include "executor.hpp"

#include <unistd.h>     // fork(), execvp()
#include <sys/wait.h>   // wait()
#include <iostream>
#include <cstdlib>      // exit()
#include <fcntl.h> 

using namespace std;

void executeExternalCommand(const Command& command) {
    // Create a child process
    pid_t id = fork();

    if (id < 0) {
        // fork() failed
        perror("fork");
        return;
    }

    if (id == 0) {
        // handle input redirection
        if (!command.inputFile.empty()){
            //inputFd is a int number, refering to open-file
            //open() is a POSIX API, returning a file descriptor number
            int inputFd = open(
                //get a pointer to the C-stype, null-terminated character sequence
                //convert C++ string filename to sequence of chars, requied by th POSIX open() API
                command.inputFile.c_str(),

                //open file in read-only mode
                O_RDONLY
            );
            
            //if Linux may not able to open the file --> failure --> inputFd = -1
            if (inputFd < 0) {
                perror("open input file");
                _exit(1);
            }
            
            //redirect standard input (fd = 0) to the opened input file
            //after this, the child process reads input from the file instead of the keyboard
            // FILENO = File Descriptor Number
            dup2(inputFd, STDIN_FILENO);
            close(inputFd);
        }

        //handle output redirection: > or >>
        if (!command.outputFile.empty()){
            int flags = O_WRONLY | O_CREAT;

            if (command.appendOutput){
                flags |= O_APPEND;
            }else {
                flags |= O_TRUNC;
            }

            int outputFd = open(
                command.outputFile.c_str(),
                flags,
                0644
            );

            if (outputFd < 0) {
                perror("open output file");
                _exit(1);
            }

            dup2(outputFd, STDOUT_FILENO);
            close(outputFd);
        }

        // execvp() requires char* arguments
        vector<char*> argv;

        for (const string& arg : command.args) {
            argv.push_back(const_cast<char*>(arg.c_str()));
        }

        // Mark the end of the argument list
        argv.push_back(nullptr);

        // Replace the child process with the requested program
        execvp(argv[0], argv.data());

        // Only runs if execvp() fails
        perror("execvp");
        _exit(1);

    } else {
        // Parent process waits for the child
        waitpid(id, nullptr, 0);
    }
}