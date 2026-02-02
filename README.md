# 🐧 mini linux bash 
A Linux shell is a command line interface (CLI) that allow users to interact with the OS by tying commands. Common shell now includes Bash, Zsh, and Fish. A mini bash is a simplified version of the Bash shell that can execute commands, handle basic input/output operations, support pipelines, and manage background processes


## `Purpose of this project`
- To demonstrate practical skills in Linux environment
- To practice programming in C/C++ for system level applications
- To understand process management, I/O redirection, and command parsing
- To implement a simple, functional shell that can be used for education purposes
- To practice collaborative software development and version control using GitHub

## `Project Objectives`
- Implement a basic shell using C/C++
- Support built-in commands like `cd` `exit` and `pwd`
- Implement input/output redirection `<` `>` `>>`
- Implement command pipelines `|`
- Support background execution using `&`
- Handle system signals like `Ctrl + C` gracefully
- Optional: maintain a command history and support auto-completion
- Showcase Linux system programming skills and command-line operations
- Add-ons (optionals): custom prompt information, colored prompt and output, help menu/banner

## `Timeline`

**Phase 1: Planning & Setup (Week1)**: Discuss project scope and featrues, set up GitHub repo for collaboration. Decide on project structure and team responsibilities

**Phase 2: Basic Shell Implementation (Week2)**: 
- Implement main loop to read user input using C/C++
- Parse commands into tokens
- Execute external programs
- Implement basic built-in commands (`cd`, `exit`, `pwd`)

**Phase 3: I/O Redirection (Week 3)**: implement input/output, append operation, test redirection with multiple commands

**Phase 4: Pipelines (Week 4)**: Implement pipe support, test execution of commands chained together

**Phase 5: Background Execution & Signals (Week 5)**: ssupport `&` to run commands in the background, Handle `Ctrl + C` to prevent shell from exieting unexpectedly

**Phase 6: Testing & Doc (Week 6)**: test all commands, redirection, pipelines, and background processes -> Write detailed documentation

## `Porject Stucture`
(can modify later)
``` text
personal-linux-shell/
├── src/
│   ├── main.cpp            # Entry point and main shell loop
│   ├── parser.cpp          # Command parsing and tokenization
│   ├── executor.cpp        # Execute built-in and external commands
│   ├── redirection.cpp     # Input/output redirection (<, >, >>)
│   ├── pipeline.cpp        # Pipe (|) handling
│   ├── signals.cpp         # Signal handling (Ctrl+C, Ctrl+Z)
│   ├── prompt.cpp          # Custom shell prompt and UI (colors, info)
│   └── utils.cpp           # Helper functions
│
├── include/
│   ├── shell.hpp           # Core shell definitions
│   ├── parser.hpp          # Parser interfaces
│   ├── executor.hpp        # Execution interfaces
│   ├── redirection.hpp     # Redirection interfaces
│   ├── pipeline.hpp        # Pipeline interfaces
│   ├── signals.hpp         # Signal handling interfaces
│   ├── prompt.hpp          # Prompt/UI interfaces
│   └── utils.hpp           # Utility interfaces
│
├── tests/
│   ├── test_commands.sh    # Basic command execution tests
│   ├── test_pipes.sh       # Pipeline tests
│   └── test_redirection.sh # I/O redirection tests
│
├── Makefile                # Build instructions (g++)
├── README.md               # Project documentation
├── .gitignore              # Ignore compiled binaries and temp files
└── LICENSE                 # Project license (optional)


