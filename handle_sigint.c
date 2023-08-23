#include "shell.h"

/**
 * sigint_handler - Handle the SIGINT signal (Ctrl+C)
 * @signal: The signal number (SIGINT)
 *
 * Return: void
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
