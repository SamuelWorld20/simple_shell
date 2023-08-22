#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in command
 * @tokens: Array containing the command tokens
 *
 * Return: 1 if the command is a built-in, 0 if not.
 */
int is_builtin(char **tokens)
{
	int index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (tokens == NULL || tokens[0] == NULL)
		return (0);

	for (index = 0; builtins[index].name != NULL;
			index++)
		if (strcmp(tokens[0],
					builtins[index].name) == 0)
			return (1);
	return (0);
}

/**
 * builin_handler - Execute a built-in command
 * @command_tokens: Array containing the command tokens
 *
 * Return: 1 if the built-in command was executed successfully, 0 if not.
 */
int builin_handler(char **command_tokens)
{
	int index;
	const struct builtin_command builtins[] = {
		{"env", _env_builtin},
		{"exit", _exit_builtin},
		{NULL, NULL}
	};

	if (command_tokens == NULL || command_tokens[0] == NULL)
		return (0);

	for (index = 0; builtins[index].name != NULL;
			index++)
	{
		if (strcmp(command_tokens[0],
					builtins[index].name) == 0)
			return (builtins[index].function(command_tokens));
	}
	return (0);
}
