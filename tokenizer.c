#include "shell.h"

/**
 * extract_command - it tokenize the input to get the first word (command)
 * @input: collected input from user
 * @command: the command inputed
 *
 * Return: Void
 */
void extract_command(const char *input, char *command)
{
	char *token;
	char temp_input[MAX_INPUT_LENGTH];

	strcpy(temp_input, input);

	token = strtok(temp_input, " ");

	if (token != NULL)
	{
		strcpy(command, token);
	}
	else
	{
		command[0] = '\0';
	}
}
