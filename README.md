# Get Next Line

Ever wanted to read a file... **one line at a time**? Neither did I — until now.  
This project implements a custom function called `get_next_line()` that reads from a file descriptor and returns the next line every time it's called. No more, no less. Yes, even if the line is 5000 characters long. Yes, even from standard input. You're welcome.

## 📜 What It Does

- Reads from a given file descriptor (including `stdin`)
- Returns **one line at a time**, including the trailing newline character (`\n`)
- Returns `NULL` on EOF or error
- Manages leftover buffer content across function calls using static variables

### Example usage:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
````

## 🧪 Compilation & Testing

You can compile the program manually, or take advantage of the provided `Makefile` which lets you easily set the buffer size and test file.

### 📦 Compile with default buffer:

```bash
make
```

### 🧯 Clean builds:

```bash
make fclean      # removes binary
make re          # rebuilds everything
```

### 🛠 Customize buffer size or test file:

```bash
make BUFFER_SIZE=42
make BUFFER_SIZE=10 FILE=file2
```

The file will be read from the `files/` directory, like so:

```
files/
├── file1.txt
├── file2.txt
├── file2.log
...
```

### 🧪 Run the test:

```bash
make t
```

This is equivalent to:

```bash
make re && ./prog files/file1.txt
```

## 🧩 File Structure

```
.
├── get_next_line.c         # Core logic
├── get_next_line_utils.c   # Helper functions
├── get_next_line.h         # Function prototype + macros
├── main.c                  # Demo / test file
├── Makefile                # Build system with test support
├── files/                  # Folder containing test files
```

## 🪲 A Few Notes

* Undefined behavior may occur if `read()` fails or is used on a binary file.
* No bonus features (yet) like handling multiple file descriptors.
* Yes, the buffer is static. Yes, it took a while to understand how static works. Yes, it was painful. 🧠

## 🔗 License

Custom license: You can use this in your own projects, just don’t pretend you wrote it without credit. Or do. I'm not your boss.

---

Because life’s too short to read the whole file at once.
