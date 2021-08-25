#include "shell.h"
/**
 * len - Function that found the length of the string
 *
 * @string: Pointer to the length of the string
 * Return: The length of the string
 */

/* Encontrar la longitud del string */
int len(char *string)
{
	int count = 0;

	while (*string != '\0')
	{
		count++;
		string++;
	}
	return (count);
}

/**
 * StrCmp - Function that compare two strings.
 *
 * @s1: Pointer to string one
 * @s2: Pointer to string two
 *
 * Return: The string representation
 */

/* Funciones de comparación para los string EXIT, ENV */
int StrCmp(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 != *s2)
		{
			return (1);
		}
		s1++, s2++;
	}

	if ((*s1 == ' ') || *s1 == '\n')
	{
		return (0);
	}
	return (1);
}

/**
 * LineIsSapce - Function that check space
 *
 * @lineptr: Pointer to the line
 *
 * Return: Sucessfully processed
 */

/* Para verificar que si hayan caracteres que procesar */
int LineIsSapce(char *lineptr)
{
	while (*lineptr)
	{
		if (*lineptr != ' ' && *lineptr != '\n' && *lineptr != EOF)
		{
			return (0);
		}
		lineptr++;
	}
	return (1);
}

/**
 * CounterWord - Function that count the words
 *
 * @lineptr: Pointer to the line
 *
 * Return: Number of words
 */

/* count words */
int CounterWord(char *lineptr)
{
	int nw, state;

	state = OUT;

	nw = 0;
	while ((*lineptr != '\0') && (*lineptr != EOF))
	{
		if ((*lineptr == ' ') || (*lineptr == '\n') || (*lineptr == '\t'))
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			nw += 1;
		}
	lineptr++;
	}
	return (nw);
}

/**
 * BuildArgs  - Function that built the
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: Void
 */
void BuildArgs(shell *PtrShell)
{
	int NumberWords = 0;

	NumberWords = CounterWord(PtrShell->lineptr);
	PtrShell->argv = (char **)malloc(sizeof(char *) * (NumberWords + 1));

	InitArrayArgv(PtrShell); /* Nos inicializa nuestro array de apuntadores */
}
