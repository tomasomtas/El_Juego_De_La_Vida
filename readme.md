Markdown
# Conway's Game of Life (CLI in C)

Simulación interactiva del famoso autómata celular **El Juego de la Vida de John Conway**, implementado en **C puro** con renderizado visual neón en consola mediante secuencias de escape ANSI.

El proyecto destaca por su arquitectura modular, la manipulación eficiente de matrices bidimensionales y el control fluido de la consola en tiempo real.

##  Características

* **Interfaz Neón Retro:** Renderizado gráfico en terminal utilizando secuencias ANSI y codificación UTF-8 (`█` para celdas vivas, `·` para celdas muertas).
* **Lógica Algorítmica Eficiente:** Evaluación iterativa de vecindad de 8 celdas con control riguroso de límites de matriz.
* **Estructura Modular:** Separación limpia de componentes en `game.h`, `game.c`, `main.c` y biblioteca de utilidades de consola `utiles.h`.
* **Salida Limpia:** Captura de eventos de teclado en tiempo real (`kbhit`) para detener la simulación de forma elegante sin interrumpir el proceso.

##  Compilación e Instalación

### Opción A: Desde la consola con GCC
```bash
gcc -Wall -Wextra -std=c11 main.c game.c -o juego_vida
Opción B: Con Code::Blocks
Abre el proyecto en Code::Blocks.

Confirma que los archivos main.c, game.c, game.h y utiles.h estén asociados al proyecto.

Presiona F9 (Build and Run).

  Uso
Ejecuta el binario en la consola:

Bash
./juego_vida
Presiona cualquier tecla durante la simulación para salir del programa limpiamente.

   1 Reglas del Juego
Supervivencia: Una celda viva con 2 o 3 vecinas vivas permanece viva.

Muerte: Una celda viva muere si tiene menos de 2 vecinas (soledad) o más de 3 (superpoblación).

Nacimiento: Una celda muerta con exactamente 3 vecinas vivas cobra vida.

   2 Futuras Mejoras
[ ] Permitir la selección de patrones iniciales clásicos (Blinker, Glider, Pulsar).

[ ] Ajustar la velocidad de simulación dinámicamente desde el teclado.

[ ] Dimensiones de tablero personalizables desde la línea de comandos.