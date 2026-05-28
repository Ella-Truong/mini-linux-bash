# 🐧 Mini Linux Shell

A lightweight Unix-like shell implemented in C/C++ that replicates core functionalities of modern Linux shells such as Bash.

This project demonstrates Linux system programming concepts, including:
- process creation
- command execution
- pipelines
- I/O redirection
- signal handling
- background process management

Designed for educational purposes and hands-on experience with operating system fundamentals.

---

## 🚧 Project Status

This project is currently under active development.

Planned implementation roadmap:
- [ ] Core shell loop
- [ ] External command execution
- [ ] Built-in commands
- [ ] Command parser
- [ ] I/O redirection
- [ ] Pipelines
- [ ] Background processes
- [ ] Signal handling
- [ ] Testing and documentation improvements

---

## ✨ Features

### Core Features
- Execute external Linux commands
- Built-in shell commands:
  - `cd`
  - `pwd`
  - `exit`
- Command parsing and tokenization
- Input/output redirection:
  - `<`
  - `>`
  - `>>`
- Command pipelines using `|`
- Background execution using `&`
- Signal handling (`Ctrl + C`, `Ctrl + Z`)

### Optional Features
- Command history
- Auto-completion
- Colored/custom shell prompt
- Welcome banner/help menu

---

## 🛠️ Tech Stack

- Language: C/C++
- Platform: Linux / Unix
- Build Tool: Makefile
- Version Control: Git + GitHub

---

## 📁 Project Structure

```bash
personal-linux-shell/
├── src/
│   ├── main.cpp               # Start shell loop and coordinate execution flow.
│   ├── parser.cpp             # Parse user input into command structures.
│   ├── executor.cpp           # Execute commands and manage processes.
│   ├── redirection.cpp        # Handle input/output redirection logic.
│   ├── pipeline.cpp           # Connect commands using Unix pipes.
│   ├── signals.cpp            # Manage shell signal handling behavior.
│   ├── prompt.cpp             # Display and update shell prompt.
│   └── utils.cpp              # Provide shared helper functions.
│
├── include/
│   ├── shell.hpp              # Core shell structures and shared interfaces.
│   ├── parser.hpp             # Parsing function declarations.
│   ├── executor.hpp           # Command execution declarations.
│   ├── redirection.hpp        # Redirection handling declarations.
│   ├── pipeline.hpp           # Pipeline processing declarations.
│   ├── signals.hpp            # Signal handling declarations.
│   ├── prompt.hpp             # Prompt rendering declarations.
│   └── utils.hpp              # Utility helper declarations.
│
├── tests/
│   ├── test_commands.sh       # Test standard command execution.
│   ├── test_pipes.sh          # Test command pipeline behavior.
│   └── test_redirection.sh    # Test input/output redirection.
│
├── docs/
│   ├── architecture.md        # Describe system architecture and modules.
│   └── process-flow.md        # Explain shell execution lifecycle.
│
├── Makefile                   # Build and compilation instructions.
├── README.md                  # Project overview and usage guide.
├── .gitignore                 # Ignore generated and temporary files.
└── LICENSE                    # Project license information.
```

---

## 📚 Documentation

Additional project documentation:
- `docs/architecture.md` — system architecture and module responsibilities
- `docs/process-flow.md` — shell execution lifecycle and process behavior

---

## 🎯 Learning Goals

This project is intended to strengthen understanding of:
- Unix/Linux process management
- system calls (`fork`, `execvp`, `pipe`, `dup2`)
- inter-process communication
- shell execution flow
- signal handling
- modular systems programming design


