/*************************************************************************/
/*                                                                       */
/*   examinar.h                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

#ifndef EXAMINAR_H
#define EXAMINAR_H

/* Funcion de conversion de grados a radianes */
#define  grad2rad(x)  ((float) (3.14159 * x) / 180.0)
#define PASO 0.1 /* Definicion del paso para el movimiento del observador */

#define WALK 1
#define EXAMINAR 2
#define FLY 3

/* Variables Globales del modulo */
int VentanaAncho = 1000, VentanaAlto = 1000; /* Tamanyo de la ventana */
int VentanaX = 50, VentanaY = 10; /* Posicion de la ventana */
GLdouble  alfa = 0.0, beta = 0.0, gamma = 0.0, z = 0.0;
GLuint cuadrica;
double ox = 0.0, oy = 1, oz = 9.; /* Posicion del observador */
double ix = 0.0, iy = 1, iz = 9 - PASO; /* Posicion del punto de interes */
int w = 1, a = 1;
int modo = WALK;

/* Abre una ventana OpenGL */
void CreateWindow(int numeroArgumentos, char ** listaArgumentos);

/* Inicia parametros de la OpenGL */
void OpenGLInit(void);

/* Funcion de dibujado */
void Draw(void);

/* Establece el area visible */
void WindowSize(int alto, int ancho);

/* Inicia las funciones de Callback */
void CallbackInit(void);

/* Define las acciones tras una pulsacion del teclado */
void Keyboard(unsigned char tecla, int x, int y);
#endif