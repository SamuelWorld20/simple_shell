#include "shell.h"

/**
 * error_not_found - Print a custom error message for a not found command
 * @arvs: Command-line arguments (unused)
 * @token_array: Tokenized array of strings
 * @cmd_num: Command number counter
 *
 * Return: Exit status (127)
 */
int error_not_found(char **arvs, char **token_array, size_t cmd_num)
{
	char *error_message;
	char *cmd_num_str = _itoa(cmd_num);
	int message_size = (strlen(arvs[0]) + (2 * strlen(": ")) +
			digit_counter(cmd_num) + strlen(token_array[0]) +
			strlen(": not found\n") + 1);

	malloc_char(&error_message, message_size,
			"error_not_found Error: malloc error");
	strcpy(error_message, arvs[0]);
	strcat(error_message, ": ");
	strcat(error_message, cmd_num_str);
	strcat(error_message, ": ");
	strcat(error_message, token_array[0]);
	strcat(error_message, ": not found\n");
	strcat(error_message, "\0");

	write(STDERR_FILENO, error_message, strlen(error_message));
	free(error_message);
	free(cmd_num_str);
	return (127);
}
