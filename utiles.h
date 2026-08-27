#ifndef UTILES_H_
#define UTILES_H_

/*
   utiles.h — Biblioteca de la catedra (Corregida con static inline)
   Programacion I — UTN INSPT — Comision 1.605 — 2026
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
        #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif
#else
    #include <unistd.h>
#endif

// *********************************************************************************
// Activa soporte de colores ANSI en la consola de Windows
// *********************************************************************************
static inline void activarColoresANSI()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

// *********************************************************************************
// Imprime x asteriscos seguidos de salto de linea
// *********************************************************************************
static inline void linea(int x)
{
    int i;
    for (i = 0; i < x; i++)
        printf("*");
    printf("\n");
}

// *********************************************************************************
// Limpia el buffer de entrada (stdin)
// *********************************************************************************
static inline void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// *********************************************************************************
// Configura la consola en UTF-8 (Windows) para mostrar tildes y enie correctamente
// *********************************************************************************
static inline void utf8()
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
}

// *********************************************************************************
// Limpia la pantalla de forma multiplataforma
// *********************************************************************************
static inline void limpiaPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// *********************************************************************************
// Cambia el color de la consola en Windows
// *********************************************************************************
static inline void Color()
{
#ifdef _WIN32
    system("color 9f");
#endif
}

// *********************************************************************************
// Pausa la ejecucion esperando una tecla
// *********************************************************************************
static inline void pausa()
{
#ifdef _WIN32
    printf("\n");
    system("pause");
#else
    printf("Presione ENTER para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
    printf("\n");
#endif
}

// *********************************************************************************
// Lee un entero de forma segura con fgets + sscanf
// *********************************************************************************
static inline int leerEntero(const char *mensaje)
{
    char buffer[100];
    int numero;
    int flag = 1;

    while (flag)
    {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &numero) == 1)
                flag = 0;
            else
                printf("Entrada invalida. Intente nuevamente.\n");
        }
    }
    return numero;
}

// *********************************************************************************
// Lee un entero validando que este dentro del rango [min, max]
// *********************************************************************************
static inline int pedirEnteroRango(const char *msj, int min, int max)
{
    int n;
    do
    {
        n = leerEntero(msj);
        if (n < min || n > max)
            printf("Fuera de rango [%d - %d]. ", min, max);
    } while (n < min || n > max);
    return n;
}

// *********************************************************************************
// Lee un flotante de forma segura con fgets + sscanf
// *********************************************************************************
static inline float leerFlotante(const char *mensaje, float *numero)
{
    char buffer[100];
    int flag = 1;

    while (flag)
    {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%f", numero) == 1)
                flag = 0;
            else
                printf("Entrada invalida. Intente nuevamente.\n");
        }
    }
    return *numero;
}

// *********************************************************************************
// Genera un entero aleatorio en el rango [valorMin, valorMax]
// *********************************************************************************
static inline int generarNumAleatorio(int valorMin, int valorMax)
{
    return (valorMin + (rand() % (valorMax - valorMin + 1)));
}

// *********************************************************************************
// Compara dos cadenas. Devuelve 1 si son iguales, 0 si son diferentes
// *********************************************************************************
static inline int sonIguales(char *texto, char *texto2)
{
    return strcmp(texto, texto2) == 0;
}

// *********************************************************************************
// Intercambia los valores de dos enteros usando punteros
// *********************************************************************************
static inline void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// *********************************************************************************
// Simula una espera con animacion de puntos suspensivos
// *********************************************************************************
static inline void retardo(float seg)
{
    int i;
    printf("CARGANDO");
#ifdef _WIN32
    for (i = 0; i < 3; i++)
    {
        Sleep((DWORD)(seg * 1000));
        printf(".");
    }
#else
    for (i = 0; i < 3; i++)
    {
        usleep((useconds_t)(seg * 1000000));
        printf(".");
    }
#endif
    printf("\n");
}

// *********************************************************************************
// Lee una cadena de forma segura con fgets
// *********************************************************************************
static inline void leerCadena(char *destino, int tamano, const char *mensaje)
{
    printf("%s", mensaje);

    if (fgets(destino, tamano, stdin) != NULL)
    {
        size_t longitud = strlen(destino);
        if (longitud > 0 && destino[longitud - 1] == '\n')
            destino[longitud - 1] = '\0';
        else
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}

#endif /* UTILES_H_ */
