#include "shell.h"

/* Inicializamos nuestro array de apuntadores */
void InitArrayPaths(shell *PtrShell) {

    int Index = 0;

    /* Asignamos el array de apuntadores: Apunta a cada ruta */
    PtrShell->AllPaths = (char **)malloc(sizeof(char *) * (PtrShell->NumberPaths + 1));

    if (PtrShell->AllPaths == NULL)
        return ;
    
    /* Inicialiszar el array de apuntadores */
    (PtrShell->AllPaths)[Index] = strtok(PtrShell->PATH, ":\0");

    /* Tambièn inicializa el ùltimo puntero para que apunta a NULL*/
    while(((PtrShell->AllPaths)[Index] = strtok(NULL, ":\0"))) {
        Index++;
    }
}

/* Contamos el número de rutas */
void NumberPaths(shell *PtrShell) {
    int i = 0;
    int count = 0;

    while ((PtrShell->PATH)[i] != '\0') {
        if ((PtrShell->PATH)[i] == ':')
            count++;
        i++;
    }
    count++; /* Para contar el caracter nulo */
    PtrShell->NumberPaths = count;

}

/* Obtenemos la ruta */
void GetPATH(shell *PtrShell)
{
    int index = 0;
    int s1equals2 = 0;

    /* While: Para obtener la variable de entorno PATH=*/
    while ((PtrShell->env)[index]) {
        s1equals2 = strncmp((PtrShell->env)[index], "PATH=", 5);

        if (!s1equals2) {
            PtrShell->PATH = (PtrShell->env)[index] + 5; /* Hacemos que PtrShell->PATH apunte a /home... */
            break;
        }
        index++;
    }

    NumberPaths(PtrShell);           /* Número de rutas */
    InitArrayPaths(PtrShell);        /* creamos y inicializamos nuestro array de apuntadores */
}