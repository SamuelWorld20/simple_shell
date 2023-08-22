#include "shell.h"

/**
 * get_user_input - it reads the user input from stdin or file
 * @input: The input buffer to store user input.
 * @input_file: pointer to input source (stdin / file)
 *
 * Return: Number of characters read, or -1 on error
 */
ssize_t get_user_input(char *input, FILE *input_file)
{
	size_t input_length;

	if (fgets(input, MAX_INPUT_LENGTH, input_file) == NULL)
	{
		if (feof(input_file))
		{
			return (0);
		}
		else
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	}

	input_length = strlen(input);
	if (input_length > 0 && input[input_length - 1] == '\n')
	{
		input[input_length - 1] = '\0';
	}
	return (input_length);
}
