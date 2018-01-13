/*************************************************************************/
/*                                                                       */
/*                 glig.h LIBRERIA DE MODELADO GEOMETRICO	             */
/*                                                                       */
/*   Rev. 3.0  01/09/2012   Universidad Jaume I de Castellón             */
/*                                                                       */
/*************************************************************************/



#ifndef GLIG_H
#define GLIG_H
#define E 0.001
#define F 0.002


/* Devuelve la coordenada x de un punto en R3 a partir de un punto (u,v) */
float xSuperQuadric(float u, float v, float R, float s1, float s2);

/* Devuelve la coordenada y de un punto en R3 a partir de un punto (u,v) */
float ySuperQuadric(float u, float v, float R, float s1, float s2);

/* Devuelve la coordenada z de un punto en R3 a partir de un punto (u,v) */
float zSuperQuadric(float u, float v, float R, float s1, float s2);

//void igCreateQuadricObject(float R, float s1, float s2);

void igCreateWireQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2);

void igWireSphere(int pu, int pv); /* s1 y s2 a 1 */

void igWireRulo(int pu, int pv); /* s1= 0.5, s2= 1 */

void igWireDado(int pu, int pv); /* s1= 0.5, s2 =0.5 */

void igWireSemiSphere(int pu, int pv); /* s1 y s2 a 1, uMax= 1, vMax= 0.5 */

void igWireCone(int pu, int pv);

void igWireCube(int pu, int pv);


void igCreateSolidQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2);

void igSolidSphere(int pu, int pv); /* s1 y s2 a 1 */

void igSolidRulo(int pu, int pv); /* s1= 0.5, s2= 1 */

void igSolidDado(int pu, int pv); /* s1= 0.5, s2 =0.5 */

void igSolidSemiSphere(int pu, int pv); /* s1 y s2 a 1, uMax= 1, vMax= 0.5 */

void igSolidCone(int pu, int pv);

void igSolidCube(void);

void igSolidCylinder(int pu, int pv);

void igSolidTest(int pu, int pv);



float nxSuperQuadric(float u, float v, float R, float s1, float s2);

float nySuperQuadric(float u, float v, float R, float s1, float s2);

float nzSuperQuadric(float u, float v, float R, float s1, float s2);

void Cylinder(float inner, float outter, float height, int slices);

void Ring(float inner1, float outter1, float inner2, float outter2, float height, int slices, int closed);

void Sphere(float radio, int slices_stacks, int orientation);

#endif