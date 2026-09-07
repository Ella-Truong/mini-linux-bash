#include "builtin.hpp"
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

bool handleBuiltin(const vector<string>& args) {
    if (args[0] == "cd"){
        if (args.size() < 2) {
            cout << "cd: missing argument" << endl;
            return true;
        }

        if (chdir(args[1].c_str()) != 0) {
            perror("cd");
        }

        return true;
    }

    if (args[0] == "pwd") {
        //create buffer to store current working directory path (1024 bytes)
        //this buffer can be reused whenever we need the current directory
        char currDir[1024];
        
        //currDir is where should I put the path, and sizeof(currDir) is how much space I can use
        //getcwd() return the pointer pointing to currDir if successful
        //it returns nullptr if it fails
        if (getcwd(currDir, sizeof(currDir)) != nullptr) {
            cout << currDir << endl;
        }else {
            perror("pwd");
        }
        return true;
    }

    if (args[0] == "echo") {
        for (size_t i = 1; i < args.size(); i++) {
            cout << args[i];

            if (i < args.size() - 1) {
                cout << " ";
            }
        }

        cout << endl;

        return true;
    }
    return false;
}