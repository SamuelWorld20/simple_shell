#include "shell.h"

/**
 * _env_builtin - Print environment variables
 * @command_tokens: Command tokens (unused)
 *
 * Return: 0 for failure, the number of printed
 * environment variables for success
 */
int _env_builtin(__attribute((unused)) char **command_tokens)
{
	int env_var_count;

	for (env_var_count = 0; __environ[env_var_count]; env_var_count++)
	{
		write(STDOUT_FILENO, __environ[env_var_count],
				strlen(__environ[env_var_count]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}
	return (env_var_count);
}
