/*************************************************************************/
/*                                                                       */
/*   material.h												             */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/


#ifndef TEXTURA_H
#define TEXTURA_H


/*********************** DECLARACION DE CONSTANTES ***********************/

#define anchoTextura 256
#define altoTextura  256



/***************** DECLARACION DE LA VARIABLES GLOBALES  *****************/

GLubyte texturaInfo[anchoTextura][altoTextura][3];


// 9.........TODO 09: USE SEVERAL TEXTURES IN THE SCENE ......................9

// 9.1........ WE'LL USE TWO TEXTURES ...................9.1
#define numTextures 14

// 9.2......... WE'LL USE REFERENCES TO THOSE TWO TEXTURES IN ORDER TO APPLY THEM TO THE OBJECTS IN THE SCENE .......9.2
GLuint textIds[numTextures];


// 11........ TODO 11: DEFINE NEW MATRIX IN ORDER TO STORE THE INFORMATION OF THE SEVERAL IMAGES ............11
GLubyte texturasInfo[numTextures][anchoTextura][altoTextura][3];


/* Lee una imagen de textura en formato tga */
void leerTextura(char *fichero);
void initTextura();

// 10........ TODO 10: DEFINE A NEW FUNCTION THAT CREATES A NEW TEXTURE FROM AN IMAGE ........... 10
void initTextureWithIndex(const char * fichero, GLuint textIndex);
// 12 ........ TODO 12: DEFINE A NEW FUNCTION THAT LOADS TGA INFO FROM SEVERAL FILES ..............11
void leerTexturaWithIndex(const char * fichero, GLuint textIndex);
// 15 ........ TODO 15: DEFINE A NEW FUNCTION TO APPLY ONE SPECIFIC TEXTURE ..............15
void applyTexture(GLuint textIndex);

#endif