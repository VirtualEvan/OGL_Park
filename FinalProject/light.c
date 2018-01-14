/*************************************************************************/
/*                                                                       */
/*   luces.c		                                                     */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"
#include "light.h"


/********************** RUTINA DE INICIO *************************/
/******************************************************************************************/
/* Inicia los parametros de iluminacion de OpenGL                                         */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void LightsInit(void)
{	
	//GLfloat lmodel_ambient [] = {0.4f, 0.4f, 0.4f, 1.0f};

	/* Par�metros del modelo de iluminaci�n */

	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	/* Activa la iluminaci�n de la escena */

	glEnable(GL_LIGHTING);	
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	//Light0();
	Light1();
	//Light2();
}


/*********************** DEFINICION DE LUCES ****************************/

/******************************************************************************************/
/* Define y activa la luz 0                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Light0 (void)
{

	GLfloat light_position[] = { 0.f, 70.f, 0.f, 1.f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat diffuse_color[] = { 0.5f, 0.5f, 0.5f, 1.f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color);

	GLfloat ambient_color[] = { 7.f, 7.f, 7.f, 1.f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color);

	GLfloat specular[] = { 0.6f, 0.6f, 0.6f, 1.f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

}

/******************************************************************************************/
/* Define y activa la luz 1                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Light1 (void)
{
	// Moon-like
	GLfloat light_position[] = { 0.f, 70.f, 0.f, -0.5f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat diffuse_color[] = { 1.f, 1.f, 1.f, 1.f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color);

	GLfloat ambient_color[] = {0.f, 0.f, 0.f, 1.f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color);

	GLfloat specular[] = { 0.6f, 0.6f, 0.6f, 1.f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

/******************************************************************************************/
/* Define y activa la luz 2                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Light2 (void)
{	
	//StreetLights
	GLfloat spot_position[] = { 0.f, 0.f, 0.f, 1.f };
	GLfloat spot_diffuse[] = { 1.f, 1.f, 1.f, 1.f };

	glLightfv(GL_LIGHT1, GL_POSITION, spot_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, spot_diffuse);
	// DEFINE LIGHT PROPERTIES SPECIFIC OF SPOT LIGHTS: direction, cutoff, exponent

	// SPOT DIRECTION: THE EMISSION CONE CENTER
	GLfloat spot_diretion[] = { 0.5f, 1.f, -10.f };
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_diretion);


	// SPOT CUTOFF: ANGLE OF THE EMISSION CONE 0 -180
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 8.f);

	// SPOT EXPONENT: THE CONCENTRATION OF THE LIGHT 0 - 90
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 90.f);
}