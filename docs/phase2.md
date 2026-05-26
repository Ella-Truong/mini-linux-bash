# Phase 2 — Parsing & Command Execution

## Overview

Phase 2 focuses on parsing user input into commands and arguments, then executing them through built-in handling or external process execution.

Core flow:

```text
Input → Parse → Execute
```

---

## Goals

- Parse commands and arguments
- Build tokenized input structure
- Implement built-in commands
- Execute external commands

---

## Example

Input:

```bash
ls -la test
```

Parsed:

```cpp
["ls", "-la", "test"]
```

---

## Planned Features

- Tokenizer/parser
- Built-ins (`cd`, `pwd`, `exit`)
- `fork()`
- `execvp()`
- `waitpid()`

---

## Notes

Phase 2 introduces core Unix process execution concepts and will continue evolving in later phases.