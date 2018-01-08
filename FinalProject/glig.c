/*************************************************************************/
/*                                                                       */
/*                 glig.c LIBRERIA DE MODELADO GEOMETRICO	             */
/*                                                                       */
/*   Rev. 3.0  01/09/2012   Universidad Jaume I de Castell�n             */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glut.h"
#include <math.h>
#include <stdio.h>
#include "glig.h"

#define PI 3.1415926535897932
#define ALFA (0.5-v)*PI
#define BETA 2*PI*u

/************************* FUNCIONES BASICAS **********************************************/
/******************************************************************************************/
/* Devuelve la coordenada x de un punto en R3 a partir de un punto (u,v)                  */
/*   de un espacio parametrico en R2                                                      */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La coordenada x de un punto en R3                                              */
/******************************************************************************************/
float xSuperQuadric (float u, float v, float R, float s1, float s2)
{
	float cosalfa, cosbeta, powcosalfa, powcosbeta;

	cosalfa = (float)cos(ALFA);
	cosbeta = (float)cos(BETA);

	if(cosalfa > 0.0)
		powcosalfa = (float)pow(cosalfa,s1);
	else
		powcosalfa =(float) - pow(- cosalfa,s1);

	if(cosbeta > 0.0)
		powcosbeta = (float)pow(cosbeta,s2);
	else
		powcosbeta = (float) - pow(- cosbeta,s2);

	return (R*powcosalfa*powcosbeta);

}


/******************************************************************************************/
/* Devuelve la coordenada y de un punto en R3 a partir de un punto (u,v)                  */
/*   de un espacio parametrico en R2                                                      */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La coordenada y de un punto en R3                                              */
/******************************************************************************************/
float ySuperQuadric (float u, float v, float R, float s1, float s2)
{
	float sinalfa, powsinalfa;

	sinalfa = (float)sin(ALFA);

	if(sinalfa > 0.0)
		powsinalfa = (float)pow(sinalfa,s1);
	else
		powsinalfa = (float)- pow(- sinalfa,s1);

	return (R*powsinalfa);
}


/******************************************************************************************/
/* Devuelve la coordenada de un punto en R3 a partir de un punto (u,v)                    */
/*   de un espacio parametrico en R2                                                      */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La coordenada z de un punto en R3                                              */
/******************************************************************************************/
float zSuperQuadric(float u, float v, float R, float s1, float s2)
{
	float cosalfa, sinbeta, powcosalfa, powsinbeta;

	cosalfa = (float)cos(ALFA);
	sinbeta=(float)sin(BETA);

	if(cosalfa > 0.0)
		powcosalfa = (float)pow(cosalfa,s1);
	else
		powcosalfa=(float) - pow(- cosalfa,s1);

	if(sinbeta > 0.0)
		powsinbeta = (float)pow(sinbeta,s2);
	else
		powsinbeta = (float) - pow(- sinbeta,s2);

	return(R*powcosalfa*powsinbeta);
}

/* Wire objects*/

void igCreateWireQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2)
{
	float u, v, inc_u, inc_v;
	float x, y, z;
	int   i, j;  /* pu es el numero de divisiones en u */
	v = 0.0f;
	u = 0.0f;
	inc_u = uMax / pu;
	inc_v = vMax / pv;
	for (j = 0; j <= pv; j++)
	{
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= pu; i++)
		{
			x = xSuperQuadric(u, v, R, s1, s2);
			y = ySuperQuadric(u, v, R, s1, s2);
			z = zSuperQuadric(u, v, R, s1, s2);
			glVertex3f(x, y, z);
			u = u + inc_u;
		}
		glEnd();
		v = v + inc_v;
	}

	for (j = 0; j <= pv; j++)
	{
		v = 0.0f;
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= pu; i++)
		{
			x = xSuperQuadric(u, v, R, s1, s2);
			y = ySuperQuadric(u, v, R, s1, s2);
			z = zSuperQuadric(u, v, R, s1, s2);
			glVertex3f(x, y, z);
			v = v + inc_v;
		}
		glEnd();
		u = u + inc_u;
	}

}

void igWireSphere(int pu, int pv)
{
	igCreateWireQuadricObject(pu, pv, 1.0, 1.0, 1.0, 1.0, 1.0);
}
void igWireRulo(int pu, int pv)
{
	igCreateWireQuadricObject(pu, pv, 1.0, 1.0, 1.0, 0.5, 1.0);
}
void igWireDado(int pu, int pv)
{
	igCreateWireQuadricObject(pu, pv, 1.0, 1.0, 1.0, 0.5, 0.5);
}
void igWireSemiSphere(int pu, int pv)
{
	igCreateWireQuadricObject(pu, pv, 1.0, 0.5, 1.0, 0.5, 0.5);
}
void igWireCone(int pu, int pv) {
	igCreateWireQuadricObject(pu, pv, 1.0, 0.5, 1.0, 2.0, 1.0);
}

void igWireCube(int pu, int pv)
{
	float p0[3] = {-0.5f, -0.5f ,0.5f};
	float p1[3] = {-0.5f, 0.5f ,0.5f};
	float p2[3] = {0.5f, 0.5f ,0.5f};
	float p3[3] = {0.5f, -0.5f ,0.5f };
	float p4[3] = {-0.5f, -0.5f ,-0.5f };
	float p5[3] = {-0.5f, 0.5f ,-0.5f };
	float p6[3] = {0.5f, 0.5f ,-0.5f };
	float p7[3] = {0.5f, -0.5f ,-0.5f };

	glBegin(GL_LINE_STRIP);
		glVertex3fv(p0);
		glVertex3fv(p1);
		glVertex3fv(p2);
		glVertex3fv(p3);
		glVertex3fv(p0);
		glVertex3fv(p4);
		glVertex3fv(p5);
		glVertex3fv(p6);
		glVertex3fv(p7);
		glVertex3fv(p4);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex3fv(p1);
		glVertex3fv(p5);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex3fv(p2);
		glVertex3fv(p6);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex3fv(p3);
		glVertex3fv(p7);
	glEnd();

}

/* Solid objects */

void igCreateSolidQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2)
{
	float u, v, inc_u, inc_v;
	float x, y, z;
	float nx, ny, nz;
	int   i, j;  /* pu es el numero de divisiones en u */
	v = 0.0f;
	u = 0.0f;
	inc_u = uMax / pu;
	inc_v = vMax / pv;
	for (j = 0; j <= pv; j++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (i = 0; i <= pu; i++)
		{
			//TEXTURA
			//glTextCoord2f(u, v);
			////
			nx = nxSuperQuadric(u, v, R, s1, s2);
			ny = nySuperQuadric(u, v, R, s1, s2);
			nz = nzSuperQuadric(u, v, R, s1, s2);
			glNormal3f(nx, ny, nz);

			x = xSuperQuadric(u, v, R, s1, s2);
			y = ySuperQuadric(u, v, R, s1, s2);
			z = zSuperQuadric(u, v, R, s1, s2);
			//glColor3f(u, v + inc_v, 0.f);
			glVertex3f(x, y, z);

			//TEXTURA
			//glTextCoord2f(u, v+inc_v);
			////
			nx = nxSuperQuadric(u, v + inc_v, R, s1, s2);
			ny = nySuperQuadric(u, v + inc_v, R, s1, s2);
			nz = nzSuperQuadric(u, v + inc_v, R, s1, s2);
			glNormal3f(nx, ny, nz);

			x = xSuperQuadric(u, v + inc_v, R, s1, s2);
			y = ySuperQuadric(u, v + inc_v, R, s1, s2);
			z = zSuperQuadric(u, v + inc_v, R, s1, s2);
			glVertex3f(x, y, z);

			u = u + inc_u;
		}
		glEnd();
		v = v + inc_v;
	}
}

void igSolidSphere(int pu, int pv)
{
	igCreateSolidQuadricObject(pu, pv, 1.0, 1.0, 1.0, 1.0, 1.0);
}
void igSolidRulo(int pu, int pv)
{
	igCreateSolidQuadricObject(pu, pv, 1.0, 1.0, 1.0, 0.5, 1.0);
}
void igSolidDado(int pu, int pv)
{
	igCreateSolidQuadricObject(pu, pv, 1.0, 1.0, 1.0, 0.5, 0.5);
}
void igSolidSemiSphere(int pu, int pv)
{
	igCreateSolidQuadricObject(pu, pv, 1.0, 0.5, 1.0, 0.5, 0.5);
}
void igSolidCone(int pu, int pv) {
	igCreateSolidQuadricObject(pu, pv, 1.0, 0.5, 1.0, 2.0, 1.0);
}

void igSolidCylinder(int pu, int pv)
{
	igCreateSolidQuadricObject(pu, pv, 1.0, 1.0, 1.0, 0.0, 1.0);
}

void igSolidTest(int pu, int pv) {
	igCreateSolidQuadricObject(pu, pv, 1.0, 1.0, 1.0, 2.5, 1.0);
}

void igSolidCube()
{
	float p0[3] = { -0.5f, -0.5f, -0.5f };
	float p1[3] = { -0.5f, 0.5f, -0.5f };
	float p2[3] = { 0.5f, 0.5f, -0.5f };
	float p3[3] = { 0.5f, -0.5f, -0.5f };
	float p4[3] = { -0.5f, -0.5f, 0.5f };
	float p5[3] = { -0.5f, 0.5f, 0.5f };
	float p6[3] = { 0.5f, 0.5f, 0.5f };
	float p7[3] = { 0.5f, -0.5f, 0.5f };

	//TRASERA
	glBegin(GL_QUADS);
	glNormal3f(0.f, 0.f, -1.f);
	glVertex3fv(p0);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);

	//DERECHA
	glNormal3f(1.f, 0.f, 0.f);
	glVertex3fv(p3);
	glVertex3fv(p2);
	glVertex3fv(p6);
	glVertex3fv(p7);

	//IZQUIERDA
	glNormal3f(-1.f, 0.f, 0.f);
	glVertex3fv(p4);
	glVertex3fv(p5);
	glVertex3fv(p1);
	glVertex3fv(p0);

	//FRONTAL
	glNormal3f(0.f, 0.f, 1.f);
	glVertex3fv(p7);
	glVertex3fv(p6);
	glVertex3fv(p5);
	glVertex3fv(p4);

	//TOP
	glNormal3f(0.f, 1.f, 0.f);
	glVertex3fv(p1);
	glVertex3fv(p5);
	glVertex3fv(p6);
	glVertex3fv(p2);

	//BOTTOM
	glNormal3f(0.f, -1.f, 0.f);
	glVertex3fv(p3);
	glVertex3fv(p7);
	glVertex3fv(p4);
	glVertex3fv(p0);
	glEnd();
}


/* Create the field */
void CreateField()
{
			glBegin(GL_QUADS);
		glNormal3f(0.f, 1.f, 0.f);
		glTexCoord2d(0, 0);
		glVertex3f(-100.f, -50.f, -1000.f);
		glTexCoord2d(-1, 0);
		glVertex3f(100.f, -50.f, -1000.f);
		glTexCoord2d(-1, -1);
		glVertex3f(100.f, -50.f, 0.f);
		glTexCoord2d(0, -1);
		glVertex3f(-100.f, -50.f, 0.f);
		glEnd();
	glPopMatrix();
}




/********************** RUTINA DE DIBUJO *********************************/


/******************************************************************************************/
/* Calcula la variacion en x para un incremento de u, derivada de x con respecto de u     */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La variacion de x con u                                                        */
/******************************************************************************************/
float dxuSuperQuadric(float u, float v, float R, float s1, float s2)
{
	return((xSuperQuadric(u + E, v, R, s1, s2) - xSuperQuadric(u - E, v, R, s1, s2)) / (2 * E));
}


/******************************************************************************************/
/* Calcula la variacion en y para un incremento de u, derivada de y con respecto de u     */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La variacion de y con u                                                        */
/******************************************************************************************/
float dyuSuperQuadric(float u, float v, float R, float s1, float s2)
{
	return((ySuperQuadric(u + E, v, R, s1, s2) - ySuperQuadric(u - E, v, R, s1, s2)) / (2 * E));
}


/******************************************************************************************/
/* Calcula la variacion en z para un incremento de u, derivada de z con respecto de u     */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La variacion de z con u                                                        */
/******************************************************************************************/
float dzuSuperQuadric(float u, float v, float R, float s1, float s2)
{
	return((zSuperQuadric(u + E, v, R, s1, s2) - zSuperQuadric(u - E, v, R, s1, s2)) / (2 * E));
}


/******************************************************************************************/
/* Calcula la variacion en x para un incremento de v, derivada de x con respecto de v     */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La variacion de x con v                                                        */
/******************************************************************************************/
float dxvSuperQuadric(float u, float v, float R, float s1, float s2)
{
	return((xSuperQuadric(u, v + E, R, s1, s2) - xSuperQuadric(u, v - E, R, s1, s2)) / (2 * E));
}


/******************************************************************************************/
/* Calcula la variacion en y para un incremento de u, derivada de y con respecto de v     */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La variacion de y con u                                                        */
/******************************************************************************************/
float dyvSuperQuadric(float u, float v, float R, float s1, float s2)
{
	return((ySuperQuadric(u, v + E, R, s1, s2) - ySuperQuadric(u, v - E, R, s1, s2)) / (2 * E));
}

/******************************************************************************************/
/* Calcula la variacion en z para un incremento de u, derivada de z con respecto de v     */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La variacion de z con u                                                        */
/******************************************************************************************/
float dzvSuperQuadric(float u, float v, float R, float s1, float s2)
{
	return((zSuperQuadric(u, v + E, R, s1, s2) - zSuperQuadric(u, v - E, R, s1, s2)) / (2 * E));
}

/******************************************************************************************/
/* Calcula la componente x del vector normal a la supercuadrica en (u,v)                  */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: Componente x del vector normal                                                 */
/******************************************************************************************/
float nxSuperQuadric(float u, float v, float R, float s1, float s2)
{
	if (v <= E) v = F;
	if (v >= 1 - E) v = 1 - F;
	return(dyuSuperQuadric(u, v, R, s1, s2)*dzvSuperQuadric(u, v, R, s1, s2) -
		dyvSuperQuadric(u, v, R, s1, s2)*dzuSuperQuadric(u, v, R, s1, s2));
}

/******************************************************************************************/
/* Calcula la componente y del vector normal a la supercuadrica en (u,v)                  */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: Componente y del vector normal                                                 */
/******************************************************************************************/
float nySuperQuadric(float u, float v, float R, float s1, float s2)
{
	if (v <= E) v = F;
	if (v >= 1 - E) v = 1 - F;
	return(dxvSuperQuadric(u, v, R, s1, s2)*dzuSuperQuadric(u, v, R, s1, s2) -
		dxuSuperQuadric(u, v, R, s1, s2)*dzvSuperQuadric(u, v, R, s1, s2));
}

/******************************************************************************************/
/* Calcula la componente z del vector normal a la supercuadrica en (u,v)                  */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: Componente z del vector normal                                                 */
/******************************************************************************************/
float nzSuperQuadric(float u, float v, float R, float s1, float s2)
{
	if (v <= E) v = F;
	if (v >= 1 - E) v = 1 - F;
	return(dxuSuperQuadric(u, v, R, s1, s2)*dyvSuperQuadric(u, v, R, s1, s2) -
		dxvSuperQuadric(u, v, R, s1, s2)*dyuSuperQuadric(u, v, R, s1, s2));
}