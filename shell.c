#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char command[MAX_INPUT_LENGTH];
	char *args[MAX_INPUT_LENGTH];
	pid_t pid;

	while (1)
	{

		if (isatty(0) == 1)
			write(1, "$ ", 2);
		fflush(stdout);
		get_user_input(input);

		if (!handle_exit(input))
		{
			char exit_message[] = "Ctrl+D pressed. Exiting shell.\n";

			write(STDOUT_FILENO, exit_message, sizeof(exit_message) - 1);
			break;
		}

		if (strcmp(input, "exit") == 0)
		{
			char exit_message[] = "Exiting shell.\n";

			write(STDOUT_FILENO, exit_message, sizeof(exit_message) - 1);
			break;
		}

		extract_command(input, command);

		if (strlen(command) > 0)
		{
			int argc = 0;
			char *token = strtok(input, " ");

			while (token != NULL)
			{
				args[argc++] = token;
				token = strtok(NULL, " ");
			}
			args[argc] = NULL;

			pid = fork();

			if (pid == 0)
			{
				if (execvp(command, args) == -1)
				{
					perror("Execution error");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid < 0)
			{
				perror("Fork error");
			}
			else
			{
				int status;
				waitpid(pid, &status, 0);
			}
		}
		fflush(stdout);
	}
	return (0);
}
