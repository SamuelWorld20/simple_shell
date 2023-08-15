#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char command[MAX_INPUT_LENGTH];

	while (1)
	{
		display_prompt();
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
			if (access(command, X_OK) == 0)
			{
				printf("%s\n", command);
			}
			else
			{
				perror("No such file or directory");
			}
		}
		fflush(stdout);
	}

	return (0);
}
