#include "shell.h"

/**
 * _exit_builtin - Built-in exit command
 * @cmd_tokens: Array of command tokens
 *
 * Return: 0 if successful, or an exit status if specified
 */
int _exit_builtin(char **cmd_tokens)
{
	if (cmd_tokens[1] != NULL)
		exit(atoi(cmd_tokens[1]));
	else
		return (EXIT_CODE);
}
