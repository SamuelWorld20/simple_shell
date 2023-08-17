#include "shell.h"

/**
 * handle_exit - it handles the end of file cmd
 * @input: it collects user input
 *
 * Return: Always 0.
 */
int handle_exit(char *input)
{
	ssize_t bytes_read = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);

	if (bytes_read == 0)
	{
		return (0);
	}
	else if (bytes_read == -1)
	{
		exit(EXIT_FAILURE);
	}

	input[bytes_read - 1] = '\0';
	return (1);
}
