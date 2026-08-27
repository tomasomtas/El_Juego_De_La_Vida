#include <stdio.h>
#include "game.h"

void inicializar_tablero(char tablero[ALTO][ANCHO]) {
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            // Usamos la funcion aleatoria de utiles.h
            tablero[i][j] = (generarNumAleatorio(0, 4) == 0) ? '1' : '0';
        }
    }
}

void imprimir_tablero(char tablero[ALTO][ANCHO], int generacion) {
    limpiaPantalla(); // Limpieza multiplataforma de utiles.h

    printf("%s=== JUEGO DE LA VIDA - GENERACION: %d ===%s\n", COLOR_BORDE, generacion, COLOR_RESET);
    linea(ANCHO + 2); // Funcion linea() de la catedra para el marco

    for (int i = 0; i < ALTO; i++) {
        printf("%s|%s", COLOR_BORDE, COLOR_RESET); // Borde izquierdo
        for (int j = 0; j < ANCHO; j++) {
            if (tablero[i][j] == '1') {
                printf("%s█%s", COLOR_VIVO, COLOR_RESET); // Bloque solido verde
            } else {
                printf("%s·%s", COLOR_MUERTO, COLOR_RESET); // Punto gris tenue
            }
        }
        printf("%s|%s\n", COLOR_BORDE, COLOR_RESET); // Borde derecho
    }

    linea(ANCHO + 2);
    printf(" Presiona enter para finalizar.\n");
}

int contar_vecinas_vivas(char tablero[ALTO][ANCHO], int fila, int col) {
    int vivas = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int n_fila = fila + i;
            int n_col = col + j;
            if (n_fila >= 0 && n_fila < ALTO && n_col >= 0 && n_col < ANCHO) {
                if (tablero[n_fila][n_col] == '1') vivas++;
            }
        }
    }
    return vivas;
}

void calcular_siguiente_generacion(char actual[ALTO][ANCHO], char siguiente[ALTO][ANCHO]) {
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            int vecinas = contar_vecinas_vivas(actual, i, j);
            if (actual[i][j] == '1') {
                siguiente[i][j] = (vecinas == 2 || vecinas == 3) ? '1' : '0';
            } else {
                siguiente[i][j] = (vecinas == 3) ? '1' : '0';
            }
        }
    }
}
