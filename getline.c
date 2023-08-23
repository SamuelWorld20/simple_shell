#include "shell.h"

/**
 * _getline - Read a line of input from stdin
 * @input_buffer: Pointer to the input buffer
 * @buffer_size: Pointer to the size of the allocated buffer
 * @exit_status: The exit status
 *
 * Return: Number of characters read on success, -1 on failure
 */
ssize_t _getline(char **input_buffer,
		size_t *buffer_size, int exit_status)
{
	ssize_t characters_read;

	prompt();
	characters_read = getline(input_buffer,
			buffer_size, stdin);
	if (characters_read == -1)
	{
		free(*input_buffer);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(exit_status);
	}
	return (characters_read);
}
