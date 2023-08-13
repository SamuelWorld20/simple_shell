# Simple Shell Project

Welcome to the Simple Shell Project repository! This project involves building a basic Unix-like shell in the C programming language.

## Description

The Simple Shell Project is an implementation of a simple command-line interpreter, commonly known as a shell. A shell allows users to interact with the operating system by executing commands, managing processes, and performing various system-related tasks.

This project aims to provide a hands-on learning experience in system programming, process management, and user interface design. By working on this project, you will gain insights into how a shell parses user input, executes commands, and manages processes.

## Features

The Simple Shell offers the following features:

- Command execution: Run external commands and display their output.
- Built-in commands: Implement some common shell built-in commands.
- Path resolution: Search for and execute commands in directories specified by the `PATH` environment variable.
- Signal handling: Handle signals such as Ctrl+C to interrupt execution.
- Background processes: Run processes in the background using the `&` symbol.

## Getting Started

To get started with the Simple Shell Project, follow these steps:

1. Clone this repository: `git clone https://github.com/SamuelWorld20/simple-shell.git`
2. Navigate to the project directory: `cd simple-shell`
3. Compile the shell program using your preferred C compiler: `gcc -o shell shell.c`
4. Run the shell program: `./shell`

## Usage

Once the shell is running, you can enter commands just like you would in a regular terminal. The shell will parse your input, execute the corresponding command, and display the output.

For example:

```
$ ./shell
$ ls
file1.txt file2.txt directory
$ echo Hello, world!
Hello, world!
$ exit

```

Refer to the [Commands](#commands) section for a list of built-in and external commands you can use.

## Commands

Here are some of the built-in commands and external commands you can use in the Simple Shell:

- `ls`: List files and directories in the current directory.
- `cd`: Change the current directory.
- `pwd`: Print the current working directory.
- `echo`: Display a message on the screen.
- `exit`: Exit the shell.

Feel free to explore additional commands and experiment with the shell's functionality.

## Contributors

This project was made possible by the contributions of the following individuals:

- [George Agbo](https://github.com/Wordschef)
- [Samuel Ejalonibu](https://github.com/SamuelWorld20)

## License

This repository is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code and resources in this repository.

---

Happy shell scripting and exploring the world of system programming!
