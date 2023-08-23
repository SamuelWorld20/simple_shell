#include "shell.h"

/**
 * _print_env - Print environment variables
 *
 * Return: 0 on success
 */
int _print_env(void)
{
	unsigned int env_index;

	for (env_index = 0; __environ[env_index]; env_index++)
		printf("%s\n", __environ[env_index]);
	return (0);
}
