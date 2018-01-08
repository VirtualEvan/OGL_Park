/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"
#include "glig.h"
#include "material.h"
#include "model.h"

/********************* ESCENA ILUMINACION ****************/

/******************************************************************************************/
/* Define un arco de la escena                                                            */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void StreetLight (void)
{
	glPushMatrix();
		glScalef(0.05,1.5,0.05);
		igSolidCylinder(10,5);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 1.6, 0.0);
		glScalef(0.25, 0.4, 0.25);
		igCreateSolidQuadricObject(80, 80, 1.0, 0.81, 1.0, 2.5, 1.0);
	glPopMatrix();
}

void Bench(void)
{
	// Patas traseras
	glPushMatrix();
	glRotatef(10.0, 1.0, 0.0, 0.0);

	glScalef(0.05, 0.5, 0.05);

	glPushMatrix();
	glTranslatef(-15.0, -0.55, 1.0);
	igSolidCube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.0, -0.55, 1.0);
	igSolidCube();
	glPopMatrix();
	glPopMatrix();

	// Patas traseras
	glPushMatrix();
		glRotatef(10.0, -1.0, 0.0, 0.0);

		glScalef(0.05, 0.5, 0.05);

		glPushMatrix();
			glTranslatef(-15.0, -0.7, 8.0);
			igSolidCube();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(15.0, -0.7, 8.0);
			igSolidCube();
		glPopMatrix();
	glPopMatrix();

	// Sujeción superior
	glPushMatrix();
		glRotatef(10.0, -1.0, 0.0, 0.0);

		glScalef(0.05, 0.75, 0.05);

		glPushMatrix();
			glTranslatef(-15.0, 0.42, -1.0);
			igSolidCube();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(15.0, 0.42, -1.0);
			igSolidCube();
		glPopMatrix();
	glPopMatrix();

	// Sujeción inferior
	glPushMatrix();
		glScalef(0.05, 0.05, 0.6);

		glPushMatrix();
			glTranslatef(-15.0, -1.0, 0.4);
			igSolidCube();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(15.0, -1.0, 0.4);
			igSolidCube();
		glPopMatrix();
	glPopMatrix();

	// Espaldar
	glPushMatrix();
		glRotatef(10.0, -1.0, .0, 0.0);

		glScalef(2.0, 0.1, 0.05);

		glTranslatef(0.0, 2.0, 0.0);
		igSolidCube();

		glTranslatef(0.0, 2.0, 0.0);
		igSolidCube();

		glTranslatef(0.0, 2.0, 0.0);
		igSolidCube();
	glPopMatrix();

	// Asiento
	glPushMatrix();
		glScalef(2.0, 0.05, 0.1);

		glTranslatef(0.0, 0.0, 1.0);
		igSolidCube();

		glTranslatef(0.0, 0.0, 2.0);
		igSolidCube();

		glTranslatef(0.0, 0.0, 2.0);
		igSolidCube();
	glPopMatrix();
}

void PineTree()
{
	// Hojas
	glPushMatrix();
		glScalef(0.8, 0.8, 0.8);
		glScalef(0.8, 1, 0.8);
		igSolidCone(80, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		igSolidCone(80, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		igSolidCone(80, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		igSolidCone(80, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		igSolidCone(80, 80);

		glScalef(0.6, 1, 0.6);
		igSolidCone(80, 80);

	glPopMatrix();

	// Tronco
	glPushMatrix();
		glTranslatef(0.0, -0.3, 0.0);
		glScalef(0.08, 0.3, 0.08);
		igSolidCylinder(80, 80);
	glPopMatrix();

}

void LongTree() {
	//Hojas
	glPushMatrix();
		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.5, 1, 0.5);
		igSolidSphere(80, 80);
	glPopMatrix();

	// Tronco
	glPushMatrix();
		glTranslatef(0.0, -0.77, 0.0);
		glScalef(0.08, 0.3, 0.08);
		igSolidCylinder(80, 80);
	glPopMatrix();
}

void Tree()
{
	//Hojas
	glPushMatrix();
		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 0.8, 0.8);
		igSolidSphere(80, 80);
	glPopMatrix();

	// Tronco
	glPushMatrix();
		glTranslatef(0.0, -0.77, 0.0);
		glScalef(0.08, 0.48, 0.08);
		igSolidCylinder(80, 80);
	glPopMatrix();
}

/******************************************************************************************/
/* Crea la display list para la escena                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/

/*
void CreateLightScene(void)
{
	scene = glGenLists (1);

	if (scene != 0)
	{
		glNewList (scene, GL_COMPILE);
		glPushMatrix();
			Copper();
			//glColor3f(0.5, 0.5, 0.25);
			SolidArches();
			//glColor3f(0.25,0.5,0.5);
			SolidFloor();
			//glColor3f (0.5f, 0.11f, 0.0f);
			glColor3f (0.0f, 0.0f, 1.0f);
			glScalef(0.5,0.5,0.5);	
			igSolidSphere(20,10);
		glPopMatrix();
		glEndList ();
	}
}
*/