#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
	//Librerías de C
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <string.h>
	#include < unistd .h >
	#include < pthread .h >
	#include "tiempo.h"
	#include "arbol.h"
	#define SIZEARRAY(x)  (sizeof(x) / sizeof((x)[0]))
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	void *busquedaA(void*);
#endif