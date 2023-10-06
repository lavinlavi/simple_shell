#include "shell.h"


char *str_maker(char *s1, char *s2);
char *_strchr(char *s, char c);

/**
 * _strlen - a function to det. string len.
 * @s: pointer to the string.
 *
 * Return: returns the length of strin
 * or -1 if error was encountered
 */

int _strlen(char *s)
{
	int i;
	char *p;

	p = s;
	if (!*p)
	{
		return (-1);
	}
	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * str_maker -  a function to merge two functions
 * @s1: pointer to the first strng.
 * @s2: pointer to the first string.
 *
 * Return: returns pointer to a new string or NULL
 */

char *str_maker(char *s1, char *s2)
{
	char *temp;
	char *new_str;
	int i, j, total_siz;

	j = 0;
	temp = NULL;
	new_str = NULL;
	i = 0;
	total_siz = _strlen(s1) + _strlen(s2);
	total_siz += 3;
	temp = malloc(sizeof(char) * total_siz);
	if (!temp)
	{
		return (NULL);
	}
	if (temp)
	{
		_memset(temp, 0, total_siz);
	}

	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '/';
	i++;
	for (j = 0; s2[j] != '\0'; j++)
	{
		temp[i + j] = s2[j];
	}
	total_siz = i + j + 1;
	temp[total_siz] = '\0';
	new_str = strdup(temp);
	free(temp);
	if (!new_str)
	{
		return (NULL);
	}
	return (new_str);
}

/**
 * _strchr -  a function to check if a characters is a delim.
 * @s: pointer to the string of delimeters.
 * @c: the character to be checked.
 *
 * Return: returns a pointer if success and NULL if failure
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s)
		{
			return (s);
		}
		s++;
	}
	if (!c)
	{
		return (s);
	}

	return (NULL);
}


