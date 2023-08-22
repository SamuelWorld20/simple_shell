#include "shell.h"

/**
 * main - Entry point of the custom shell program
 * @ac: Number of command-line arguments
 * @arvs: Array of command-line argument strings
 * @envp: Array of environment variable strings
 *
 * Return: Exit status of the shell program
 */
int main(__attribute((unused)) int ac,
		__attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	int stat = 0;
	char *input, *delim, *which;
	size_t allocated_bytes, cmd_num;
	char **token_array;

	signal(SIGINT, sigint_handler);
	input = NULL;
	allocated_bytes = cmd_num = 0;
	delim = " \n";
	while (1)
	{
		cmd_num++;
		_getline(&input, &allocated_bytes, stat);

		token_array = array_maker(input, delim);
		if (!(*token_array))
			stat = 0;
		else
		{
			if (is_builtin(token_array))
			{
				if (builin_handler(token_array) == EXIT_CODE)
				{
					free_main(token_array, input);
					exit(stat);
				}
			}
			else
			{
				which = _which(token_array[0]);
				if (which !=  NULL)
					stat = _fork(which, token_array);
				else
					stat = error_not_found(arvs, token_array, cmd_num);
			}
		}
		free_main(token_array, input);
		input = NULL;
	}
	return (0);
}
