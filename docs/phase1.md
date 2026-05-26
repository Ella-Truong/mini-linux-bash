# Phase 1 — Basic Shell Loop

## Overview

Built the foundational shell lifecycle loop.

```text
Prompt → Read Input → Process → Repeat
```

---

## Implemented

- Shell prompt
- Continuous loop
- User input handling
- Basic exit behavior

---

## Example

```cpp
while (true) {
    displayPrompt();
    getline(cin, input);

    processInput(input);
}
```

---

## Notes

Phase 1 will continue evolving as new shell features are added.