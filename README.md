# pipex

This project is part of the **42 Prague curriculum**.<br>
This project recreates the basic behavior of the Unix shell pipeline (`|`).<br>
The goal is to understand how pipes, file descriptors, and process control work under Unix systems.<br>

## Overview

The program executes a sequence of commands connected by pipes, just like the shell does:

```sh
./pipex infile cmd1 cmd2 outfile
```

is equivalent to:
```sh
< infile cmd1 | cmd2 > outfile
```

Each command runs in its own process. The output of one command is passed as input to the next using **pipes**.


## 📦 Compilation

Build the program with:
```sh
make
```

## 🚀 Usage
Basic two-command example<br>
```sh
./pipex infile "ls -l" "wc -l" outfile
```
Equivalent shell command:
```sh
< infile ls -l | wc -l > outfile
```
Multiple commands (bonus)
```sh
./pipex infile "cat" "grep hello" "wc -l" outfile
```
Equivalent shell command:
```sh
< infile cat | grep hello | wc -l > outfile
```
Here document mode (bonus)
```sh
./pipex here_doc LIMITER cmd1 cmd2 ... cmdn outfile
```
Equivalent shell command:
```sh
cmd1 << LIMITER | cmd2 | ... | cmdn >> outfile
```
In this mode:
- Input is read from stdin until a line matching LIMITER is found.
- The output is appended to outfile instead of overwriting it.
## 🧹 Makefile Rules

```make``` – Compile the executable binary<br>

```make clean``` – Remove object files (.o)<br>

```make fclean``` – Remove object files and the compiled executable binary<br>

```make re``` – Recompile everything (equivalent to fclean + make)<br>
## ⚙️ Notes

The project must be Norminette-compliant.

Only the following functions are allowed:

open, close, read, write, malloc, free, access, dup, dup2,
execve, exit, fork, pipe, perror, wait, waitpid
