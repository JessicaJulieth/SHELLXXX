#include "shell.h"

/**
 * InitArrayArgv - Function that tokenized the arguments
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: Void
 */
void InitArrayArgv(shell *PtrShell)
{
	int Index = 0;

	(PtrShell->argv)[Index] = strtok(PtrShell->lineptr, " \n\t\0");

	Index++;
	while (((PtrShell->argv)[Index] = strtok(NULL, " \n\t\0")))
	{
		Index++;
	}
}
