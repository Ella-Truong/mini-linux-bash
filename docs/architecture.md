# Shell Architecture

## Overview

This project implements a lightweight Unix-like shell in C/C++ designed to replicate core functionalities of modern Linux shells such as Bash.

The shell supports:
- external command execution
- built-in commands
- pipelines
- input/output redirection
- background process execution
- signal handling

The project is structured into modular components responsible for parsing, execution, pipelines, redirection, and signal management.

---

# High-Level Architecture

```text
User
  ↓
Terminal
  ↓
Mini Shell
  ├── Prompt Module
  ├── Parser Module
  ├── Executor Module
  ├── Pipeline Module
  ├── Redirection Module
  └── Signal Module
  ↓
Linux System Calls
  ↓
Operating System Kernel
```

---

# Module Responsibilities

| Module | Responsibility |
|---|---|
| `main.cpp` | Shell loop and execution coordination |
| `parser.cpp` | Parse user input into command structures |
| `executor.cpp` | Execute commands and manage processes |
| `pipeline.cpp` | Handle Unix pipelines |
| `redirection.cpp` | Handle file input/output redirection |
| `signals.cpp` | Manage signal handling behavior |
| `prompt.cpp` | Display shell prompt |
| `utils.cpp` | Shared helper utilities |

---

# Execution Flow

```text
Display prompt
   ↓
Read user input
   ↓
Parse command
   ↓
Execute command
   ↓
Handle pipes/redirection if needed
   ↓
Wait for foreground process
   ↓
Return to prompt
```

---

# Process Model

The shell follows a parent-child process architecture.

## Parent Process
The shell itself acts as the parent process responsible for:
- reading user input
- maintaining shell state
- spawning child processes

## Child Processes
External Linux commands execute inside child processes created using `fork()`.

Example:

```text
Shell Process
   ↓ fork()
Child Process
   ↓ execvp()
Linux Command Executes
```

---

# Design Goals

The project is designed to:
- demonstrate Unix/Linux systems programming concepts
- practice process management and IPC
- explore shell execution behavior
- provide hands-on experience with Linux system calls
- build a modular and maintainable systems project