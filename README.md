# get_next_line

WIP

This is my second project at 19 Coding School. `get_next_line` is a function which provides a handy way to read a file line by line. The aim of the exercise is to discover static variables and 
get used with file reading in C.

The project guidelines are available [here](/subjects/en.subject.pdf); note that this repository is NOT fully-compliant with the requirements, mainly for organizational purposes.
Students, be aware, if you steal my code, you'll face the consequences 😈 

## Why is your coding-style so weird? 🤮

I strictly follow the *Norm* enforced by the school. The Norm is a laundry list of coding conventions that students have to follow to the letter on pain of seeing their work sanctioned with a 0. The Norm forbids for instance the use of `goto`, `do while` and `for` loops, requires to declare every variable at the top of a function, and restrains the number of lines, columns and routines. Such restrictions are sometimes leading to the use of obscure code golf tricks 😅

## Prerequisite knowledge

+ Static variables remain in memory even when the program goes out of the scope where the variable is declared.
+ Static variables are auto-initialized to 0.
+ There is a limit of the number of files that can be simultaneously opened. The `FOPEN_MAX` symbolic constant from `stdio.h` represents this limit.

## WIP

est-ce que les entrées et sorties standard comptent dans le nombre de fichiers ouverts ?

différence entre FOPEN_MAX et OPEN_MAX

utiliser des listes chainées plutôt que strjoin pour ne réallouer que le nécessaire