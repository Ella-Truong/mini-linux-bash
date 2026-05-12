# 🐧 Mini Linux Bash

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
- CI/CD: GitHub Actions

---

## 📁 Project Structure

```bash
personal-linux-shell/
├── .github/
│   └── workflows/
│       └── ci.yml
│
├── src/
│   ├── main.cpp
│   ├── parser.cpp
│   ├── executor.cpp
│   ├── redirection.cpp
│   ├── pipeline.cpp
│   ├── signals.cpp
│   ├── prompt.cpp
│   └── utils.cpp
│
├── include/
│   ├── shell.hpp
│   ├── parser.hpp
│   ├── executor.hpp
│   ├── redirection.hpp
│   ├── pipeline.hpp
│   ├── signals.hpp
│   ├── prompt.hpp
│   └── utils.hpp
│
├── tests/
│   ├── test_commands.sh
│   ├── test_pipes.sh
│   └── test_redirection.sh
│
├── docs/
│   ├── architecture.md
│   └── process-flow.md
│
├── Makefile
├── README.md
├── .gitignore
└── LICENSE
