#ifndef SHELL_H
#define SHELL_H
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct Shell - Struct for tha containt all the fuctions
 * @env: Pointer to environment variable.
 * @lineptr: Pointer to the line
 * @n: Number of characters the contain the lineptr
 * @PATH: Pointer to the path
 * @NumberPaths: Number of paths
 * @AllPaths: Pointer to the array to all the paths
 * @argv: Pointer to the getline
 * @Terminal: Pointer to the terminal
 * @Interactivo: Pointer to the interactive mode
 * @GetPATH: Pointer to get the path
 */
typedef struct Shell
{
	/* Atributos o varialbes */
	char **env;                   /* Variable de entorno */
    /* Lo utiliza la función Getline para obtener la línea */
	char *lineptr;
	size_t n;                     /* Número de caracteres que hay en lineptr */
	char *PATH;                   /* Puntero a PATH */
	int  NumberPaths;             /* Número de rutas */
	char **AllPaths;              /* Array de apuntadores: Todas las rutas */
	char **argv;

	/* Métodos o function */
	/* Check si estamos dentro una terminal o no */
	int (*Terminal)(void);
	void (*Interactivo)(struct Shell *PtrShell);/* Modo interactivo de la shell */
	void (*GetPATH)(struct Shell *PtrShell);        /* Obtenemos el PATH */
} shell;

/**
 * InitShell- Init the data structure.
 *
 * @PtrShell: Pointer to the struct of data
 * @env: pointer to the environment variable
 * Return: void
 */
/* Inicializar la estructua de datos de tipo shell */
void InitShell(shell *PtrShell, char **env);
void Interactivo(shell *PtrShell);
void GetPATH(shell *PtrShell);
void InitArrayArgv(shell *PtrShell);
int Execve(shell *PtrShell);
void Interactivo(shell *PtrShell);
int Terminal(void);
void BuildArgs(shell *PtrShell);
int LineIsSapce(char *lineptr);
int StrCmp(char *s1, char *s2);
void printENV(char **env);
int len(char *string);

#endif
