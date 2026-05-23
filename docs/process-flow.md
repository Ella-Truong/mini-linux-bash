# Shell Process Flow

## Overview

This document describes the planned execution lifecycle of the mini shell.

The shell operates as an interactive loop that continuously:
1. displays a prompt
2. reads user input
3. parses commands
4. executes processes
5. returns control to the user

---

# High-Level Flow

```text
Start Shell
   ↓
Display Prompt
   ↓
Read User Input
   ↓
Parse Command
   ↓
Check Built-in Command
   ↓
Execute Command
   ↓
Handle Pipes/Redirection
   ↓
Wait for Process Completion
   ↓
Return to Prompt
```

---

# Shell Lifecycle

## 1. Shell Startup

When the program launches:
- shell initializes runtime state
- signal handlers may be configured
- shell enters interactive loop

---

## 2. Prompt Display

The shell displays a command prompt to indicate readiness for user input.

Example:

```bash
myshell>
```

Possible future improvements:
- current working directory
- colored prompt
- username display

---

## 3. User Input

The shell reads a full line of input from standard input.

Example:

```bash
ls -la
```

The raw command string is passed to the parser module.

---

## 4. Command Parsing

The parser converts raw input into structured command data.

Responsibilities:
- tokenize arguments
- detect pipes (`|`)
- detect redirection (`<`, `>`, `>>`)
- detect background execution (`&`)

Example:

```bash
cat file.txt | grep hello > out.txt
```

Parsed into:
- multiple commands
- pipeline connections
- output redirection target

---

## 5. Built-in Command Handling

The shell checks whether the command is built into the shell itself.

Examples:
- `cd`
- `pwd`
- `exit`

Built-in commands execute directly inside the shell process.

---

## 6. Process Creation

External commands execute inside child processes.

The shell creates child processes using:

```cpp
fork()
```

The child process replaces itself with the target program using:

```cpp
execvp()
```

---

# Example Process Flow

Example command:

```bash
ls -la
```

Execution flow:

```text
Shell Process
   ↓ fork()
Child Process
   ↓ execvp("ls")
Linux executes command
   ↓
Output displayed to terminal
```

---

## 7. Pipeline Handling

For commands connected with pipes:

```bash
cat file.txt | wc -l
```

The shell:
- creates Unix pipes
- forks multiple child processes
- redirects process input/output streams

Core system calls:
- `pipe()`
- `dup2()`

---

## 8. Redirection Handling

The shell supports:
- input redirection
- output redirection
- append redirection

Examples:

```bash
echo hello > out.txt
cat < input.txt
```

The shell redirects file descriptors before command execution.

---

## 9. Background Execution

Commands ending with `&` execute in the background.

Example:

```bash
sleep 10 &
```

The shell:
- launches child process
- does not wait for completion
- immediately returns prompt

---

## 10. Signal Handling

The shell handles terminal signals such as:
- `SIGINT` (Ctrl+C)
- `SIGTSTP` (Ctrl+Z)

Signal handling ensures:
- shell remains interactive
- foreground processes receive signals properly

---

# Design Goals

The process flow is designed to:
- model real Unix shell behavior
- demonstrate Linux process management
- illustrate inter-process communication
- provide educational systems programming experience