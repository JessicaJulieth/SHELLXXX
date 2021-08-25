#include "shell.h"

/**
 * InitArrayPaths - Function that init the pointers to the arrays
 *
 * @PtrShell: Pointer to the struct
 *
 * Return: Void
 */
/* Inicializamos nuestro array de apuntadores */
void InitArrayPaths(shell *PtrShell)
{
	int Index = 0;

	/* Asignamos el array de apuntadores: Apunta a cada ruta */
	PtrShell->AllPaths = (char **)malloc(sizeof(char *) *
	(PtrShell->NumberPaths + 1));

	if (PtrShell->AllPaths == NULL)
		return;

	/* Inicialiszar el array de apuntadores */
	(PtrShell->AllPaths)[Index] = strtok(PtrShell->PATH, ":\0");

	/* Tambièn inicializa el ùltimo puntero para que apunta a NULL*/
	while (((PtrShell->AllPaths)[Index] = strtok(NULL, ":\0")))
	{
		Index++;
	}
}

/**
 * NumberPaths - Function that get the number of paths
 *
 * @PtrShell: Pointer to the structure
 *
 * Return: Void
 */
/* Contamos el número de rutas */
void NumberPaths(shell *PtrShell)
{
	int i = 0;
	int count = 0;

	while ((PtrShell->PATH)[i] != '\0')
	{
		if ((PtrShell->PATH)[i] == ':')
			count++;
		i++;
	}
	count++; /* Para contar el caracter nulo */
	PtrShell->NumberPaths = count;
}

/**
 * GetPATH - Function that get all path
 *
 * @PtrShell: Pointer to the structure
 *
 * Return: Number of words
 */
/* Obtenemos la ruta */
void GetPATH(shell *PtrShell)
{
	int index = 0;
	int s1equals2 = 0;

	/* While: Para obtener la variable de entorno PATH=*/
	while ((PtrShell->env)[index])
	{
		s1equals2 = strncmp((PtrShell->env)[index], "PATH=", 5);

		if (!s1equals2)
		{
/* Hacemos que PtrShell->PATH apunte a /home... */
			PtrShell->PATH = (PtrShell->env)[index] + 5;
			break;
		}
		index++;
	}

	NumberPaths(PtrShell);           /* Número de rutas */
	/* creat and inicializamos nuestro array de apuntadores */
	InitArrayPaths(PtrShell);
}

/**
 * CopyPath - Function that copy command to the path
 *
 * @dest: Pointer to the find path
 * @src1: Pointer to the path
 * @src2: Pointer to the command type
 * Return: Number of words
 */
void CopyPath(char *dest, char *src1, char *src2)
{
	int state = 1;

	while (*src1 || *src2) /* comando y path */
	{
		if (*src1)
			*dest++ = *src1++;
		else if (!*src1 && state)
		{
			*dest++ = '/';
			state = 0;
		}
		else if (*src2 != '\n')
			*dest++ = *src2++;
		else if (*src2 == '\n')
			src2++;
	}
	*dest = '\0'; /* deberia ser NULL?? */
}
