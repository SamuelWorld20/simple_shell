#include "shell.h"

/**
 * _unsetenv - Unset an environment variable
 * @var_name: The name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *var_name)
{
	unsigned int env_num;
	int new_env_num, free_new_env_num, found_num;
	char **new_env;

	new_env = NULL;
	env_num = _env_length();
	found_num = _env_name_exists(var_name);
	if (found_num != -1)
	{
		new_env = malloc_array(new_env, env_num,
				"_unsetenv() Error: new_env malloc failed");
		for (new_env_num = 0; __environ[new_env_num]; new_env_num++)
		{
			if (new_env_num != found_num)
			{
				new_env[new_env_num] = malloc(sizeof(char) *
						strlen(__environ[new_env_num]));
				if (new_env[new_env_num] == NULL)
				{
					perror("_unsetenv() Error: new_env[new_env_num] malloc failed");
					for (free_new_env_num = 0; free_new_env_num < new_env_num;
							free_new_env_num++)
						free(new_env[new_env_num]);
					free(new_env);
					return (-1);
				}
				strcpy(new_env[new_env_num], __environ[new_env_num]);
			}
		}
		new_env[env_num] = NULL;
		__environ = new_env;
	}
	return (0);
}
