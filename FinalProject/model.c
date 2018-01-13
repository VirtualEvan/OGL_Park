/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"
#include "glig.h"
#include "model.h"


/******************** SCENE *************************/

void InitScene(void)
{
	scene = glGenLists(1);

	if (scene != 0)
	{
		glNewList(scene, GL_COMPILE);

		LongTree();
		

		glEndList();
	}
}

/********************* MODELS ****************/

void Test() {
	GLUquadricObj *Cylinder; // Create pointer for our cylinder

	Cylinder = gluNewQuadric(); // Create our new quadric object
	gluQuadricDrawStyle(Cylinder, GLU_FILL); //FILL also can be line(wire)
	gluQuadricNormals(Cylinder, GLU_SMOOTH); // For if lighting is to be used.
	gluQuadricOrientation(Cylinder, GLU_INSIDE);
	gluQuadricTexture(Cylinder, GL_TRUE);// if you want to map a texture to it.

	applyTexture(5);					 // Draw 
	gluSphere(Cylinder, 0.8, 80, 80);
	gluDeleteQuadric(Cylinder);

}


void Floor() {
	applyTexture(1);

	GLUquadric* quad = gluNewQuadric();
	gluQuadricDrawStyle(quad, GLU_FILL); //FILL also can be line(wire)
	gluQuadricNormals(quad, GLU_SMOOTH); // For if lighting is to be used.
	gluQuadricOrientation(quad, GLU_INSIDE);
	gluQuadricTexture(quad, GL_TRUE);// if you want to map a texture to it.

	gluDisk(quad,0,2,80,80);
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
		glTranslatef(0.0, 1.75, 0.0);
		Ring(0.01, 0.03, 0.03, 0.05, 0.1, 80, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 1.45, 0.0);
		glScalef(0.2, 0.2, 0.2);
		igSolidSemiSphere(80, 80);
	glPopMatrix();

	applyTexture(9);
	glPushMatrix();
		glTranslatef(0.0, 1.42, 0.0);
		glScalef(3.0, 0.3, 3.0);
		Cylinder(0.585, 0.585, 0.25, 80);
	glPopMatrix();

	applyTexture(6);
	glPushMatrix();
		glTranslatef(0.0, 1.42, 0.0);
		glScalef(3.0, 1.0, 3.0);
		Ring(0.585, 0.6, 0.585, 0.6, 0.25, 80, 1);
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
		glTranslatef(0.0, 0.45, 0.0);
		Cylinder(0.15, 0.15, 0.1, 80);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, -0.1, 0.0);
		glScalef(0.5, 0.5, 0.5);
		igCreateSolidQuadricObject(80, 80, 1.0, 0.8, 1.0, 1.0, 1.0);
	glPopMatrix();
	
	applyTexture(9);
	glPushMatrix();
		glTranslatef(0.0, -0.55, 0.0);
		glScalef(3.0, 0.3, 3.0);
		Cylinder(1.0, 1.0, 0.4, 80);
	glPopMatrix();

	applyTexture(6);
	glPushMatrix();
		glTranslatef(0.0, -0.5, 0.0);
		glScalef(3.0, 1.0, 3.0);
		Ring(1.0, 1.05, 1.0, 1.05, 0.4, 80, 1);
	glPopMatrix();
}

void StreetLight (void)
{
	applyTexture(8);
	glPushMatrix();
		glTranslatef(0.0, 1.35, 0.0);
		glScalef(0.05,1.5,0.05);
		Cylinder(1.0, 1.0, 3.0, 80);
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
	applyTexture(5);
	glPushMatrix();
		glTranslatef(0.0, 1.04, 0.0);
		glScalef(0.8, 0.8, 0.8);
		glScalef(0.8, 1, 0.8);
		Cylinder(0.0, 0.9, 1.3, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		//igSolidCone(80, 80);
		Cylinder(0.0, 0.9, 1.3, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		//igSolidCone(80, 80);
		Cylinder(0.0, 0.9, 1.3, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		//igSolidCone(80, 80);
		Cylinder(0.0, 0.9, 1.3, 80);

		glTranslatef(0.0, 0.5, 0.0);
		glScalef(0.8, 1, 0.8);
		//igSolidCone(80, 80);
		Cylinder(0.0, 0.9, 1.3, 80);

		glScalef(0.6, 1, 0.6);
		//igSolidCone(80, 80);
		Cylinder(0.0, 0.9, 1.3, 80);
	glPopMatrix();

	// Tronco
	applyTexture(4);
	glPushMatrix();
		glScalef(0.08, 0.3, 0.08);
		Cylinder(1.0, 1.0, 2.5, 80);
	glPopMatrix();

}

void LongTree() {
	applyTexture(5);
	//Hojas
	glPushMatrix();
		glTranslatef(0.0, 0.53, 0.0);
		glScalef(0.5, 1.3, 0.5);
		glRotatef(90, 1.0, 0.0, 0.0);
		Sphere(0.8, 80, 1);
	glPopMatrix();

	applyTexture(3);
	// Tronco
	glPushMatrix();
		glTranslatef(0.0, -0.49, 0.0);
		glScalef(0.08, 0.3, 0.08);
		Cylinder(1.0, 1.0, 2.0, 80);
	glPopMatrix();
}

void Tree()
{
	applyTexture(5);
	//Hojas
	glPushMatrix();
		glTranslatef(0.0, 0.5, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		Sphere(0.8, 80, 1);
	glPopMatrix();

	applyTexture(2);
	// Tronco
	glPushMatrix();
		glTranslatef(0.0, -0.3, 0.0);
		glScalef(0.08, 0.48, 0.08);
		Cylinder(1.0, 1.0, 3.0, 80);
	glPopMatrix();
}
