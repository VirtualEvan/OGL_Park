/*************************************************************************/
/*                                                                       */
/*   modelado.h												             */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

#ifndef MODELADO_H
#define MODELADO_H

/* Identificador para la display list de la escena */
GLuint scene;

/* Crea la display list para la escena */
void CreateLightScene (void);

void StreetLight(void);

void Bench(void);

void PineTree(void);

void LongTree(void);

void Tree(void);

#endif