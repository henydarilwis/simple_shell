#include "shell.h"


/**
 * _isalpha - checks for alpha chara
 * @c: The char to input
 * Return: 1 if c is alpha, 0 else
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string integer
 * @s: the string to be conver
 * Return: 0 no numb in stri, conver number else
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}

		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}

/**
 * is_delim - checks if chara is  delimeter
 * @c: the character to ck
 * @delim: the delimeter string
 * Return: 1  true, 0 if else
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * interactive - returns true if  shell inter mode
 * @info: struct addresress
 *
 * Return: 1 if inter mode,0 else
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
