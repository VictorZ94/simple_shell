# Simple Shell

![](https://img.shields.io/badge/Tackeshi%20Ramirez-Holberton__School-red) ![](https://img.shields.io/badge/Victor%20Zuluaga-Holberton__School-red) ![](https://img.shields.io/badge/Linux-Bash-lightgrey) ![](https://img.shields.io/badge/Project-Shell-lightgrey) ![](https://img.shields.io/badge/Release-v1.0-blue) ![](https://img.shields.io/badge/Issues-Memory__leaks-blue)


Shell is a program's computer that receives commands from prompt of the terminal. This program reads lines from either a file or the terminal, interprets them, and generally executes other commands.

Shell works the follow standard files descriptor POSIX.


| File descriptor | Purpose       |  POSIX name  | stdio stream |
| :------------ : |:-------------:|:------------:|:------------:|
|       0         |standard input | STDIN_FILENO |   stdin      |
|       1         |standard output| STOUT_FILENO |   stdout     |
|       2         |standard error | STERR_FILENO |   stderr     |


### Process 

A process is an instance of an executing program. A program is a file containing a range of information that describes how to construct a process at run time. (PID & PPID).


### Commands

The shell interprets the words it reads according to a language, the specification of which is outside the scope of this man page (refer to the BNF in the POSIX 1003.2 document).  Essentially though, a line is read and if the first word of the line (or after a control operator) is not a reserved word, then the shell has recognized a simple command. Otherwise, a complex command or some other special construct may have been recognized.

### Simple Commands

If a simple command has been recognized, the shell performs the following actions:

      1. Leading words of the form “name=value” are stripped off and assigned to the environment of the simple command.  Redirection operators and their arguments (as described below) are stripped off and saved for processing.

      2. The remaining words are expanded as described in the section called “Expansions”, and the first remaining word is considered the command name and the command is located.  The remaining words are considered the arguments of the command. If no command name resulted, then the “name=value” variable assignments recognized in item 1 affect the current shell.

      3. Redirections are performed as described in the next section.

## How to use this program.

      1. Clone the repo is your terminal.
      >You must have git installed.

      ` git clone https://github.com/VictorZ94/simple_shell.git  `

      2. Compile the program.
      >You must have gcc installed

      ` gcc -Wall -Werror -wextra -pedantic -o mysh `

      3.  Execute your program.

      ` ./mysh `

### FlowChart

```flow
st=>start: Start
op=>operation: isatty()
cond=>condition: getline != EOF?
cond2=>condition: stat() == 0
cond3=>condition: fork() == 0
op2=>operation: execve() == 0
op3=>operation: command no found
op4=>operation: Return 0
e=>end: wait

st->op->cond
cond(yes)->cond2
cond(no)->op4
cond2(yes)->cond3
cond2(no)->op3
cond3(yes)->op2
cond3(no)->e
```

> all rigth reserved 

