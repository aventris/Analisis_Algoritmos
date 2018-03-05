/*Burbuja simple*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leerArchivo.h"
int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	int *A = (int *)malloc(sizeof(int)*n);
	int j,i,aux;
	printf("%i\n",n);
	A = arreglo(n);

	/*Simple bubble method*/
	for(i = 0; i < (n-2);i++){
		for(j = 0; j <= (n-2)-i;j++){
			if(A[j] > A[j+1]){
				aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
			}
		}
	}
	/*Impresion de numeros*/
	printf("\n*******************************************Numeros ordenados\n\n\n");
	for(i = 0; i < n;i++)
		printf("%d ",A[i]);
	printf("\n");
	
	free(A);
	return 0;
}
