#include "executor.hpp"

#include <unistd.h>     // fork(), execvp()
#include <sys/wait.h>   // wait()
#include <iostream>
#include <cstdlib>      // exit()

using namespace std;

void executeExternalCommand(const vector<string>& args) {
    // Create a child process
    pid_t id = fork();

    if (id < 0) {
        // fork() failed
        perror("fork");
        return;
    }

    if (id == 0) {
        // Child process

        // execvp() requires char* arguments
        vector<char*> argv;

        for (const string& arg : args) {
            argv.push_back(const_cast<char*>(arg.c_str()));
        }

        // Mark the end of the argument list
        argv.push_back(nullptr);

        // Replace the child process with the requested program
        execvp(argv[0], argv.data());

        // Only runs if execvp() fails
        perror("execvp");
        exit(1);

    } else {
        // Parent process waits for the child
        wait(NULL);
    }
}