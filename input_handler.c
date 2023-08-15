#include "main.h"

/**
 * get_user_input - it reads the user input
 * @input: it collects the user input
 *
 * Return: no return
 */
void get_user_input(char *input)
{
	fgets(input, MAX_INPUT_LENGTH, stdin);
	input[strlen(input) - 1] = '\0';
}
