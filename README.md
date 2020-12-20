# The Monty Language

### Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

### Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$

### Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/0x19-stacks_queues_lifo_fifo$

## Installation

### Clone this repository in your terminal:

$ git clone https://github.com/kaci65/monty

$ cd monty

## Compilation & Output

### This code will be compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

This code will be executed this way:

$ ./monty bytecodes/00.m

    Any output must be printed on stdout
    Any error message must be printed on stderr

Here is a link to a GitHub repository that could help you making sure your errors are printed on stderr:
Link: https://github.com/sickill/stderred

## Authors
 
    David Mutune
    Wanjiku
