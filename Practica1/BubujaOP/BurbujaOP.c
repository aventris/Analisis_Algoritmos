#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tiempo.h"

void main(int argc, char *argv[]){
		
	double utime0, stime0, wtime0,utime1, stime1, wtime1;

	int n ;
	int *A;
	int i,j,aux;
	
	n = atoi(argv[1]);
	//printf("Tamanio: %d\n",n);

	A = (int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	/* Tiempo inicial */
	uswtime(&utime0, &stime0, &wtime0);

	/* Comienzo de algoritmo */
	bool cambios = true;
	i=0;	
	while((i<n-1)&&(cambios != false)){
		cambios=false;
		for( j = 0; j <= (n-2)-i ; j++){if(A[j] > A[j+1]){
				aux = A[j+1];
				A[j+1] = A[j];
				A[j] = aux;
				cambios = true;
			}
		}
		i++;
	}
	/* Fin de algorimo*/
	/* Tiempo final */
	uswtime(&utime1, &stime1, &wtime1);
	/* Imprimir arreglo ordenado 
	for(i=0;i<n;i++)	
		printf("%d\n",A[i]);
	*/
	/*Librear memoria */
	free(A);
	/* Imprimir tiempos */	
	printf("Prueba con %d numeros\n",n );
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	exit(0);
}