# Get Next Line

## 🚀 Overview
Reading from a file descriptor line by line can be tedious. **Get Next Line** (`get_next_line`) simplifies this process by reading and returning one line at a time. This project will help you understand file descriptors, buffer management, and static variables in C.

---

## 📜 Function Prototype
```c
char *get_next_line(int fd);
```

| Function | Description |
|----------|-------------|
| `get_next_line` | Reads a single line from the given file descriptor. |

#### 📂 **Files to Submit**
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`
- `Makefile`

#### 🛠 **Compilation**
Compile using:
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
(`BUFFER_SIZE` can be adjusted to optimize performance.)

---

## 📌 Key Features
✔ Reads a file line by line.  
✔ Works with **file descriptors** (files, stdin, pipes).  
✔ **Does not leak memory** (ensuring efficient `malloc()` usage).  
✔ Includes a **configurable buffer size** (`BUFFER_SIZE`).  

---

## ⚠ Important Constraints
- You **cannot** use `lseek()`.
- **Global variables are forbidden**.
- Your function **must handle any `BUFFER_SIZE` value** efficiently.
- Reading a **binary file results in undefined behavior**.
- Your function **must return `NULL`** on error or EOF.

---

## ✅ Usage Example
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd))) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 📜 License
This project is part of the **42 School Curriculum** and is for educational purposes only.

🔥 Happy Coding! 🚀

