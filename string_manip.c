#include "shell.h"

/**
 * _strcpy - a function to copy the contents of 
 * one string to another.
 * @dest: the destination.
 * @src: the source
 */

void _strcpy(char *dest, char *src)
{
	int len, i;

	len = _strlen(src);
	if (dest == NULL || src == NULL)
	{
		return;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[len] = '\0';
}

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
	for (i = 0; i < total_siz; i++)
	{
		temp[i] = 0;
	}
	i = 0;
	if (temp == NULL)
	{
		return (NULL);
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
	new_str = _strdup(temp);
	free(temp);
	if (!new_str)
	{
		return (NULL);
	}
	return (new_str);
}

/**
 * _strdup - a function to replicate a string
 * @s1: the string.
 *
 * Return: returns a pointer to the new string.
*/

char *_strdup(char *s1)
{
	int i, j;
	char *new_str;

	if (!s1)
	{
		return (NULL);
	}

	i = _strlen(s1);
	new_str = malloc(sizeof(char) * (i + 1));

	for (j = 0; j < i; j++)
	{
		new_str[j] = s1[j];
	}
	new_str[i] = '\0';

	return (new_str);
}
