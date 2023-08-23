#include "shell.h"

/**
 * rev_string - Reverse a string
 * @input_str: The string to be reversed
 *
 * Return: void
 */
void rev_string(char *input_str)
{
	int start_index;
	int end_index;
	char tmp_char;

	start_index = 0;
	end_index = strlen(input_str) - 1;
	while (start_index < end_index)
	{
		tmp_char = input_str[start_index];
		input_str[start_index] = input_str[end_index];
		input_str[end_index] = tmp_char;
		start_index++;
		end_index--;
	}
}

/**
 * _itoa - Convert an integer to a string
 * @num: The integer to convert
 *
 * Return: the converted string
 */
char *_itoa(size_t num)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int i = 0;

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	str[i] = '\0';
	rev_string(str);

	return (str);
}
