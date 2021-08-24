#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct Shell {

    /* Atributos o varialbes */
    char **env;                   /* Variable de entorno */
    char *lineptr;                /* Lo utiliza la función Getline para obtener la línea */
    size_t n;                     /* Número de caracteres que hay en lineptr */
    char *PATH;                   /* Puntero a PATH */
    int  NumberPaths;             /* Número de rutas */
    char **AllPaths;              /* Array de apuntadores: Todas las rutas */
    char **argv;

    /* Métodos o function */
    int (*Terminal) (void);                         /* Check si estamos dentro una terminal o no */
    void (*Interactivo)(struct Shell *PtrShell);    /* Modo interactivo de la shell */
    void (*GetPATH)(struct Shell *PtrShell);        /* Obtenemos el PATH */
} shell;

void InitShell(shell *PtrShell, char **env);        /* Inicializar la estructua de datos de tipo shell */
void Interactivo(shell *PtrShell);
void GetPATH(shell *PtrShell);

#endif

