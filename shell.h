#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

ssize_t get_user_input(char *input, FILE *input_file);
void display_prompt(void);
void extract_command(const char *input, char *command);
int handle_exit(char *input);

#endif /* MAIN_H */
