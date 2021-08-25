#include "shell.h"

/**
 * printENV - Function that print all environment
 *
 * @env: Pointer to the env
 * Return: Void
 */

/* Imprimir variables de entorno */
void printENV(char **env)
{
	while (*env != NULL)
	{
		write(1, *env, len(*env));
		write(1, "\n", 1);
		env++;
	}
}
