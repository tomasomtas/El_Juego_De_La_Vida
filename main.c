#include "game.h"

int main() {
    // Configuración inicial de la consola (de utiles.h)
    utf8();
    activarColoresANSI();

    char tablero_a[ALTO][ANCHO];
    char tablero_b[ALTO][ANCHO];
    char (*actual)[ANCHO] = tablero_a;
    char (*siguiente)[ANCHO] = tablero_b;

    int generacion = 1;
    inicializar_tablero(actual);

    while (1) {
        imprimir_tablero(actual, generacion++);
        calcular_siguiente_generacion(actual, siguiente);

        // Intercambio de punteros de matrices
        char (*temp)[ANCHO] = actual;
        actual = siguiente;
        siguiente = temp;

#ifdef _WIN32
        // Pausa de 500 milisegundos (medio segundo por generacion)
        // Puedes cambiar 500 por 800 si lo quieres aun mas lento
        Sleep(500);

        // Si el usuario presiona CUALQUIER TECLA, sale limpiamente del bucle
        if (kbhit()) {
            break;
        }
#else
        usleep(500000);
#endif
    }

    limpiaPantalla();
    printf("\n ¡Simulacion finalizada con exito!\n\n");
    return 0;
}
