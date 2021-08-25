#include "shell.h"

/**
 * Interactivo - Interactive mode
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: void
 */
/* Modo interactivo */
void Interactivo(shell *PtrShell)
{
	PtrShell->GetPATH(PtrShell);

	while (write(1, "$ ", 2) &&
	((getline(&(PtrShell->lineptr), &(PtrShell->n), stdin)) != EOF))
	{
		if ((LineIsSapce(PtrShell->lineptr) == 1) || *(PtrShell->lineptr) == '\n')
			continue;
		if (StrCmp(PtrShell->lineptr, "exit") == 0)
		{ /* Antes de salir Liberar memoria */
			free(PtrShell->lineptr);
			free(PtrShell->AllPaths);
			exit(0);
		}
		else if (StrCmp(PtrShell->lineptr, "env") == 0)
		{ /* Imprimimos las variables de entorno */
			printENV(PtrShell->env);
		}

		BuildArgs(PtrShell);
		Execve(PtrShell);
		if (PtrShell->argv != NULL)
		{
			free(PtrShell->argv);
			PtrShell->argv = NULL;
		}
	}
	free(PtrShell->lineptr);
	free(PtrShell->AllPaths);
}

/**
 * Terminal - Functions that define a terminal
 *
 * Return: Process suscessfull
 */
/* Modo interactivo */
/* Para verificar si estamos en una terminal o no */
int Terminal(void)
{
	if (!isatty(STDIN_FILENO))
		return (0);
	else
		return (1);
}

/**
 * InitShell- Init the data structure.
 *
 * @PtrShell: Pointer to the struct of data
 * @env: pointer to the environment variable
 * Return: void
 */
/* Modo interactivo */
/* Inicialozamos la estructura de datos*/
void InitShell(shell *PtrShell, char **env)
{
	PtrShell->env = env;
	PtrShell->lineptr = NULL;
	PtrShell->n = 0;
	PtrShell->PATH = NULL;
	PtrShell->NumberPaths = 0;
	PtrShell->AllPaths = NULL;
	PtrShell->argv = NULL;

	PtrShell->Terminal = Terminal;
	PtrShell->Interactivo = Interactivo;
	PtrShell->GetPATH = GetPATH;
}
