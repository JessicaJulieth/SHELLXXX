#include "shell.h"

/* Imprimir variables de entorno */
int printENV(char **env) {

    /*while(*env != NULL) {
        write(1, *env, 1024);
        write(1, "\n", 1);
         printf("%s\n", *env); 
            env++; 
    }*/
    /* imprime todas las variables de entorno pero nos da segmentation fall*/
    ssize_t size;
    int index;
    for (index = 0; *env[index]; index++) {
        for (size = 0; env[index][size]; size++)
            ;
        write(STDOUT_FILENO, env[index], size);
        write(STDOUT_FILENO, "\n", 1);
    }
    return(1);
    free(*env);
    free(size);
}

/* Funciones de comparación para los string EXIT, ENV */
int StrCmp(char *s1, char *s2) {

    while (*s2) {
        if (*s1 != *s2) {
            return (1);
        }
        s1++, s2++;
    }

    if ((*s1 == ' ') || *s1 == '\n') {
        return (0);
    }
    return (1);
}

/* Para verificar que si hayan caracteres que procesar */
int LineIsSapce(char *lineptr) {

    while (*lineptr) {
        if (*lineptr != ' ' && *lineptr != '\n' && *lineptr != EOF) {
            return (0);
        }
        lineptr++;
    }


    return 1;
}

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count words */
int CounterWord(char *lineptr)
{
    int nw, state;
    state = OUT;

    nw = 0;
    while ((*lineptr != '\0') && (*lineptr != EOF)) {

        if ((*lineptr == ' ') || (*lineptr == '\n') || (*lineptr == '\t')) {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            nw += 1;
        }
        lineptr++;
    }
    return (nw);
}

void InitArrayArgv(shell *PtrShell) {

    int Index = 0;

    (PtrShell->argv)[Index] = strtok(PtrShell->lineptr, " \n\t\0");

    Index++;
    while(((PtrShell->argv)[Index] = strtok(NULL, " \n\t\0"))) {
        Index++;
    }
}

void BuildArgs (shell *PtrShell) {

    int NumberWords = 0;

    NumberWords = CounterWord(PtrShell->lineptr); 
    PtrShell->argv = (char **)malloc(sizeof(char *) * (NumberWords + 1));

    InitArrayArgv(PtrShell); /* Nos inicializa nuestro array de apuntadores */
}

int Execve(shell *PtrShell) {

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

/* Modo interactivo */
void Interactivo(shell *PtrShell) {

    PtrShell->GetPATH(PtrShell);
        
    while(write(1, "$ ", 2) && ((getline(&(PtrShell->lineptr), &(PtrShell->n), stdin)) != EOF)) {

        if ((LineIsSapce(PtrShell->lineptr) == 1) || *(PtrShell->lineptr) == '\n')
            continue;
        if (StrCmp(PtrShell->lineptr, "exit") == 0) { /* Antes de salir Liberar memoria */
            free(PtrShell->lineptr);
            free(PtrShell->AllPaths);
            exit(0);
        }
        else if (StrCmp(PtrShell->lineptr, "env") == 0) { /* Imprimimos las variables de entorno */
            printENV(PtrShell->env);
        }

        BuildArgs(PtrShell);
        Execve(PtrShell);
        if (PtrShell->argv != NULL) {
            free(PtrShell->argv);
            PtrShell->argv = NULL;
        }
    }
    free(PtrShell->lineptr);
    free(PtrShell->AllPaths);
}

/* Para verificar si estamos en una terminal o no */
int Terminal() {

    if (!isatty(STDIN_FILENO))
        return (0);
    else
        return (1);
}

/* Inicialozamos la estructura de datos*/
void InitShell(shell *PtrShell, char **env) {

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