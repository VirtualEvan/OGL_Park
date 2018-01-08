/*************************************************************************/
/*                                                                       */
/*   material.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include <stdio.h>
#include "glut.h"
#include "texture.h"


void leerTextura (char *fichero)
{
	int   i, j;
	char  r, g, b, c;
	FILE  *tga;

	/* Apertura del fichero TGA */
	if ((tga = fopen(fichero, "rb")) == NULL)
		printf ("Error abriendo el fichero: %s\n", fichero);
	else
	{
		/* Lee los 18 primeros caracteres de la cabecera */
		for (j=1; j<=18; j++)
			fscanf (tga, "%c", &c);

		/* Lee la imagen */
		for (j=altoTextura-1; j>=0; j--)
		{
			for (i=anchoTextura-1; i>=0; i--)
			{
				fscanf(tga, "%c%c%c", &b, &g, &r); 
				texturaInfo[j][i][0] = (GLubyte)r;
				texturaInfo[j][i][1] = (GLubyte)g;
				texturaInfo[j][i][2] = (GLubyte)b;
			}
		}
		fclose(tga);   /* Cierre del fichero TGA */
	}
}

// 3..... TODO 03 ............CREATE TEXTURE FROM IMAGE INFO .............3

void initTextura()
{

	// 4..... TODO 04 ............ READ INFO FROM TGA FILE.............4
	//leerTextura("grass.jpg");
	leerTextura("grass.tga");

	// 5..... TODO 05 ............ CREATE NEW TEXTURE FROM IMAGE FILE INFO  ..........5
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, texturaInfo);
	// 6..... TODO 06 ............. TEXTURE WRAP .....................................6
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	/*
	 * WE MUST INDICATE THE CORRESPONDENCE BETWEEN TEXTURE COORDINATES AND THE VERTICES OF THE SURFACE WE WANT TO TEXTURE
	 * IF THE TEXTURE COORDINATES ARE OUT OF RANGE [0 - 1] THE TEXTURE CAN BE:
	 * + REPEATED : GL_REPEAT
	 * + STRETCHED: GL_CLAMP
	 */
	
	// 7..... TODO 07 ............... TEXTURE FILTER ..................................7

	/*
	* WHEN THE TEXTURE SIZE DOESN'T MATCH THE SIZE OF THE SURFACE, OPENGL USES A FILTER IN ORDER TO INTERPOLATE
	* THE IMAGE PIXELS AND IN THIS WAY ADJUST IT TO THE SURFACE. WHEN THE SURFACE IS SMALLER THAN THE TEXTURE, OPENGL
	* USES A MINIFICATION FILTER (GL_TEXTURE_MIN_FILTER); WHEN THE SURFACE IS BUGGER THAN THE TEXTURE, OPENGL USES
	* A MAGNIFICATION FILTER. THERE ARE SEVERAL TYPES OF FILTERS LIKE:
	*    + GL_LINEAR: SMOOTHS THE IMAGE
	*    + GL_NEAREST: 16-BITS GAME STYLE 
	*/	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

// 13....... TODO 13: DEFINE THE BODY FOR leerTexturaWithIndex FUNCTION ................13
void leerTexturaWithIndex(const char * fichero, GLuint textIndex) {
	int   i, j;
	char  r, g, b, c;
	FILE  *tga;

	/* Apertura del fichero TGA */
	if ((tga = fopen(fichero, "rb")) == NULL)
		printf("Error abriendo el fichero: %s\n", fichero);
	else
	{
		/* Lee los 18 primeros caracteres de la cabecera */
		for (j = 1; j <= 18; j++)
			fscanf(tga, "%c", &c);

		/* Lee la imagen */
		for (j = altoTextura - 1; j >= 0; j--)
		{
			for (i = anchoTextura - 1; i >= 0; i--)
			{
				fscanf(tga, "%c%c%c", &b, &g, &r);
				texturasInfo[textIndex][j][i][0] = (GLubyte)r;
				texturasInfo[textIndex][j][i][1] = (GLubyte)g;
				texturasInfo[textIndex][j][i][2] = (GLubyte)b;
			}
		}
		fclose(tga);   /* Cierre del fichero TGA */
	}
}


// 14....... TODO 14: DEFINE THE BODY FOR initTexturaWithIndex FUNCTION ................14
void initTextureWithIndex(const char * fichero, GLuint textIndex) {
	leerTexturaWithIndex(fichero, textIndex);

	// CREATE THE TEXTURE REFERENCE
	glGenTextures(1, &textIds[textIndex]);

	// BIND TEXTURE TO REFERENCE
	glBindTexture(GL_TEXTURE_2D, textIds[textIndex]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, texturasInfo[textIndex]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


// 16 ........ TODO 16: DEFINE THE BODY OF THE FUNCTION FOR APPLYING ONE SPECIFIC TEXTURE ..............16
void applyTexture(GLuint textIndex) {
	glBindTexture(GL_TEXTURE_2D, textIds[textIndex]);
}

