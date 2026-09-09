#include "builtin.hpp"
#include <unistd.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <filesystem>

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

    if (args[0] == "export") {
        //export needs a variable assignment, like export NAME=Ella
        if (args.size() < 2) {
            cout << "export: missing argument" << endl;
            return true;
        }
        
        //get the assignment" "NAME=Ella"
        string assignment = args[1];
        
        //search for the position of =
        //find() return index of '=' if found
        //or string::npos if '=' does not exist
        size_t equalPos = assignment.find('=');

        if (equalPos == string::npos) {
            cout << "export: invalid format" << endl;
            return true;
        }
        
        //split "NAME=Ella" into name="NAME" and value="Ella"
        string name = assignment.substr(0, equalPos);
        string value = assignment.substr(equalPos + 1);
        
        //Add the variable to the shell's environment
        //The child process will inherit this env after folk()
        if (setenv(name.c_str(), value.c_str(), 1) != 0) {
            perror("export");
        }

        return true;
    }

    // CUSTOM BUILT-IN PROGRAMS
    // myinfo --> process information
    if (args[0] == "myinfo") {
        char cwd[1024];

        cout << "PID: " << getpid() << endl;
        cout << "PPID: " << getppid() << endl;
        cout << "UID: " << getuid() << endl;

        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            cout << "Working directory: " << cwd << endl;
        }else {
            perror("myinfo");
        }

        return true;
    }

    //procinfo --> show info of the custom shell itself
    if (args[0] == "procinfo") {
        ifstream file("/proc/self/status");

        if (!file) {
            perror("procinfo");
            return true;
        }

        string line;
        
        cout << "Process Information: " << endl;

        while (getline(file, line)) {
            if (line.rfind("Name:", 0) == 0 ||
                line.rfind("State:", 0) == 0 ||
                line.rfind("Pid:", 0) == 0 ||
                line.rfind("PPid:", 0) == 0 ||
                line.rfind("Uid:", 0) == 0) {
                    cout << line << endl;
            }
        }

        return true;
    }

    //memtop
    if (args[0] == "memtop") {
        //store information about each process
        struct ProcessMemory {
            int pid;
            string name;
            long rssKB;
        };
        
        //get total system memory
        long totalMemoryKB = 0;

        ifstream memFile("/proc/meminfo");

        if (!memFile) {
           perror("memtop");
           return true;
        }

        string line;

        while(getline(memFile, line)) {
            if (line.rfind("MemTotal:", 0) == 0) {
                stringstream ss(line);

                string label;
                ss >> label >> totalMemoryKB;

                break;
            }
        }

        if (totalMemoryKB == 0) {
            cout << "memtop: could not read total memory" << endl;
            return true;
        }

        //store all processes
        vector<ProcessMemory> processes;

        //go through /proc
        for (const auto& entry : filesystem::directory_iterator("/proc")) {
            if(!entry.is_directory()){
                continue;
            }

            string directoryName = entry.path().filename().string();

            //only process directions have numeric names
            if (directoryName.empty() || !all_of(directoryName.begin(), directoryName.end(), ::isdigit)) {
                continue;
            }

            int pid = stoi(directoryName);

            //open /proc/PID/status
            string statusPath = entry.path().string() + "/status";

            ifstream statusFile(statusPath);

            if(!statusFile){
                continue;
            }

            string name;
            long rssKB = 0;

            //read process information
            while (getline(statusFile, line)) {
                if(line.rfind("Name:", 0) == 0){
                    stringstream ss(line);

                    string label;
                    ss >> label >> name;

                }else if (line.rfind("VmRSS:", 0) == 0){
                    stringstream ss(line);

                    string label;
                    ss >> label >> rssKB;
                }
            }

            //store process information
            if(!name.empty()){
                processes.push_back({pid, name, rssKB});
            }
        }

        //sort process by RAM usage
        sort(processes.begin(), processes.end(), 
            [](const ProcessMemory& a, const ProcessMemory& b) {
            return a.rssKB > b.rssKB;
            });

        // Display results
        cout << endl;
        cout << "========== MEMORY ANALYSIS ==========" << endl;
        cout << endl;

        cout << "Total RAM: "
            << totalMemoryKB / 1024
            << " MB"
            << endl;

        cout << endl;
        cout << "PID\tNAME\t\tRAM\t\t%" << endl;
        cout << "---------------------------------------------" << endl;

        for (const auto& process : processes) {
            double percentage =
                (static_cast<double>(process.rssKB) / totalMemoryKB) * 100;

            cout << process.pid << "\t"
                << process.name << "\t\t"
                << process.rssKB / 1024 << " MB\t"
                << percentage << "%"
                << endl;
        }

        cout << endl;

        return true;
    }


    return false;
}