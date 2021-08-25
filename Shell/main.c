#include "shell.h"

/**
 * main - Function main
 *
 * @argc: Argument to
 * @argv: Array of
 * @env: Environment variable
 *
 * Return: retunr 0
 */
/* Shell */
int main(int argc, char **argv, char **env)
{

	shell VShell;
	(void) argc;
	(void) argv;

	InitShell(&VShell, env);              /* inicializamos la estructura */

	if (!(VShell.Terminal)())                  /* Modo no interactivo*/
		puts("No\n");
	else
	{                                     /* Modo interactivo */
		(VShell.Interactivo)(&VShell);
	}
	return (0);
}
