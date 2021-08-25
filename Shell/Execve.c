#include "shell.h"

/**
 * Execve  - Function that excecute the command.
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: Child process
 */
int Execve(shell *PtrShell)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		execve(*(PtrShell->argv), PtrShell->argv, NULL);
	}
	else
	{
		wait(&status);
	}
	return (child_pid);
}
