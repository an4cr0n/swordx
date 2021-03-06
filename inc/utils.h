#pragma once

#include <stdbool.h>

typedef enum {ERROR_TYPE = -1, OTHER , REGULAR_FILE, DIRECTORY, SYMBOLIC_LINK} fileType;

/* 
** This function is meant to be used after a call to malloc or calloc to check the results and acts accordingly.
**/
void check_heap(void *);

/*
** This function return an enum fileType depending on the type of file passed as argument
*/
fileType type_of_file(char *);

/*
** This function returns if a path points to a symlink or not
*/
bool isSymlink(char *);

/*
**  Prints a logo
*/
void print_logo(void);

/*
** Prints a special version of the logo
*/
void print_pirate_logo(void);
