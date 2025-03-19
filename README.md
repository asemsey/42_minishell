# Minishell

`minishell` is a simple shell implementation written in C. The goal of this project was to recreate Bash as closely as possible, handling command execution, environment variables, input/output redirection, and pipelines. This project was part of the 42 curriculum and provided in-depth experience with process management and system calls in Unix-based operating systems.

## Features

- **Command Execution**: Executes binaries from the system’s PATH.
- **Built-in Commands**: Implements several built-in commands like `cd`, `echo`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Pipes (`|`)**: Supports execution of multiple commands connected via pipes.
- **Redirections (`>`, `<`, `>>`, `<<`)**: Handles input and output redirections.
- **Environment Variables**: Allows exporting, modifying, and retrieving environment variables.
- **Signal Handling**: Manages signals like `Ctrl+C`, `Ctrl+D`, and `Ctrl+Z` to behave like Bash.
- **Error Handling**: Provides meaningful error messages for invalid commands and syntax errors.

## Usage

To build and run `minishell`, follow these steps:

    ```bash
    git clone https://github.com/yourusername/minishell.git
    cd minishell
    make
    ./minishell
    ```

Once `minishell` is running, you can enter commands as you would in a typical shell. It supports built-in commands, executing system binaries, and using pipes and redirections.

Example usage:

```sh
$ echo "Hello, world!"
Hello, world!

$ ls -l | grep minishell

$ echo "test" > file.txt
$ cat < file.txt
test
```


asemsey -> https://github.com/asemsey

fnikzad -> https://github.com/Fayeza99
