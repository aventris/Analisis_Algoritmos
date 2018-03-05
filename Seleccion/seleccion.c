/*Burbuja simple*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leerArchivo.h"
int main(int argc, char const *argv[])
{

	//Se creara solo la memoria necesaria para los numeros en
	//los argumentos argc 
	int *A,n = atoi(argv[1]);
	A = (int *)malloc(sizeof(int)*n);
	int i,k,p;
	int temp;
	A = arreglo(n);
	/*selection sort method*/
	for(k = 0; k < (n-2); k++){
		p = k;
		for(i = k+1; i <= (n-1);i++){
			if(A[i] < A[p]){
				p = i;
			}
		}
		temp = A[p];
		A[p] = A[k];
		A[k] = temp;
	}
	/*Numeros ordenados*/
	//printf("\nNumeros ordenados\n");
	for(i = 0; i < n;i++)
		fprintf(stdout,"%d\n",A[i]);
	free(A);
	return 0;
}