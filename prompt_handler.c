#include "main.h"

/**
 * display_prompt - it displays $ indicating the user should pass in an input
 *
 * Return: No return value
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		char *prompt = "$ ";

		write(STDOUT_FILENO, prompt, strlen(prompt));
	}
}
