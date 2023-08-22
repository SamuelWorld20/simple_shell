#include "shell.h"

/**
 * digit_counter - Count the number of digits in a number
 * @num: The number for which to count digits
 *
 * Return: number of digits in the given number.
 */
int digit_counter(size_t num)
{
	int num_digits = 0;

	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		num_digits++;
	}

	return (num_digits);
}
