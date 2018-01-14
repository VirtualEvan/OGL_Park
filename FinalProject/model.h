/*************************************************************************/
/*                                                                       */
/*   modelado.h												             */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

#ifndef MODELADO_H
#define MODELADO_H

#define SIZE 75

/* Identificador para la display list de la escena */
GLuint scene;
GLuint trees;
GLuint benches;
GLuint stlights;
GLuint fountain;


/* Crea la display list para la escena */
void InitScene (void);

void StreetLight(void);

void Bench(void);

void PineTree(void);

void LongTree(void);

void Tree(void);

void Fountain(void);

void Tile(int texture);


void Sky(int size);

void Grass(int texture);

void setFloor(float size);
void setBenches(void);
void setLights(void);
void setTrees(void);
void setLTrees(void);
void setPTrees(void);
void setFountain(void);

void Test(void);

#endif