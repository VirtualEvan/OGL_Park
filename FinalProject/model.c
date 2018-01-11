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


/******************** SCENE *************************/

void InitScene(void)
{
	scene = glGenLists(1);

	if (scene != 0)
	{
		glNewList(scene, GL_COMPILE);
		/*
			glPushMatrix();
				//igSolidCube();
				glTranslatef(1.f, 0.f, 0.f);
				glScalef(0.7f, 0.7f, 0.7f);
				glRotatef(90, 0.0, 0.5, 0.5);
				igSolidCylinder(80, 80);
				//Floor(1);
			glPopMatrix();
			glPushMatrix();
				//igSolidCube();
				glTranslatef(-1.f, 0.f, 0.f);
				glScalef(0.7f, 0.7f, 0.7f);
				glRotatef(90, 0.0, 0.5, -0.5);
				igSolidCylinder(80,80);
				//Floor(1);
			glPopMatrix();
		*/
		Floor();
		glEndList();
	}
}

/********************* MODELS ****************/

void Floor() {
	applyTexture(1);
	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad,4,4,15,80,80);
	gluDeleteQuadric(quad);
}


void Tile(int texture) {
	applyTexture(texture);
	glBegin(GL_QUADS);
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2d(0, 0);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glTexCoord2d(-1, 0);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glTexCoord2d(-1, -1);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glTexCoord2d(0, -1);
		glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
}



void Fountain() {
	applyTexture(1);

	glScalef(0.5, 0.5, 0.5);

	glPushMatrix();
	glTranslatef(0.0, 1.67, 0.0);
	glScalef(0.05, 0.02, 0.05);
	igSolidCylinder(80, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.45, 0.0);
	glScalef(0.2, 0.2, 0.2);
	igSolidSemiSphere(80, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.35, 0.0);
	glScalef(1.3, 0.1, 1.3);
	igSolidCylinder(80, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.07, 0.0);
	glScalef(0.3, 0.3, 0.3);
	glRotatef(180, 1.0, 0.0, 0.0);
	igCreateSolidQuadricObject(80, 80, 1.0, 0.7, 1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.35, 0.15, 0.35);
	glTranslatef(0.0, 5.0, 0.0);
	glRotatef(180, 1.0, 0.0, 0.0);
	igCreateSolidQuadricObject(80, 80, 1.0, 0.81, 1.0, 2.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(0.0, 2, 0.0);
	glRotatef(180, 1.0, 0.0, 0.0);
	igCreateSolidQuadricObject(80, 80, 1.0, 0.75, 1.0, 2.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.38, 0.0);
	glScalef(0.15, 0.08, 0.15);
	igSolidCylinder(80, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.1, 0.0);
	glScalef(0.5, 0.5, 0.5);
	igCreateSolidQuadricObject(80, 80, 1.0, 0.8, 1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.7, 0.0);
	glScalef(3.0, 0.25, 3.0);
	igSolidCylinder(80, 80);
	glPopMatrix();
}

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
	int wood = 7;
	int metal = 8;
	// Patas traseras
	glPushMatrix();
		glRotatef(10.0, 1.0, 0.0, 0.0);
		glScalef(0.05, 0.5, 0.05);

		applyTexture(metal);
		glPushMatrix();
			glTranslatef(-15.0, -0.55, 1.0);
			igSolidCube();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(15.0, -0.55, 1.0);
			igSolidCube();
		glPopMatrix();
	glPopMatrix();

	// Patas delanteras
	applyTexture(metal);
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
	applyTexture(metal);
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
	applyTexture(metal);
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
	applyTexture(wood);
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
	applyTexture(wood);
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
	applyTexture(4);
	glPushMatrix();
		glTranslatef(0.0, -0.3, 0.0);
		glScalef(0.08, 0.3, 0.08);
		igSolidCylinder(80, 80);
	glPopMatrix();

}

void LongTree() {
	applyTexture(5);
	//Hojas
	glPushMatrix();
		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.5, 1, 0.5);
		igSolidSphere(80, 80);
	glPopMatrix();

	applyTexture(3);
	// Tronco
	glPushMatrix();
		glTranslatef(0.0, -0.77, 0.0);
		glScalef(0.08, 0.3, 0.08);
		igSolidCylinder(80, 80);
	glPopMatrix();
}

void Tree()
{
	applyTexture(5);
	//Hojas
	glPushMatrix();
		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 0.8, 0.8);
		igSolidSphere(80, 80);
	glPopMatrix();

	applyTexture(2);
	// Tronco
	glPushMatrix();
		glTranslatef(0.0, -0.77, 0.0);
		glScalef(0.08, 0.48, 0.08);
		igSolidCylinder(80, 80);
	glPopMatrix();
}
