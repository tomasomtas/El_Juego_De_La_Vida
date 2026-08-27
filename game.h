#ifndef GAME_H
#define GAME_H

#include "utiles.h"

#define ALTO 20
#define ANCHO 40

// Codigos de color ANSI
#define COLOR_VIVO  "\033[1;32m" // Verde brillante
#define COLOR_MUERTO "\033[90m"   // Gris oscuro
#define COLOR_BORDE  "\033[1;36m" // Cyan brillante
#define COLOR_RESET  "\033[0m"

void inicializar_tablero(char tablero[ALTO][ANCHO]);
void imprimir_tablero(char tablero[ALTO][ANCHO], int generacion);
void calcular_siguiente_generacion(char actual[ALTO][ANCHO], char siguiente[ALTO][ANCHO]);

#endif // GAME_H
