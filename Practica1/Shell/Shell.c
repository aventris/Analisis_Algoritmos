#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"

void main(int args, char *argv[]){
	/* Variables para medir el tiempo */
	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	/* Variables del algoritmo */
	int n = atoi(argv[1]);
	int b,i,temp;
	int k = trunc(n/2);
	//printf("n: %d\n",n );
	
	/* Crear arreglo de numeros de forma dinamica */
	int *A;
	A = (int*)malloc(n*sizeof(int));

	/* Obtener datos del archivo */
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
	//printf("K: %d\n",k );
	
	/* Comienza la medicion de tiempo */
	uswtime(&utime0, &stime0, &wtime0);

	/*Inicio de algoritmo*/
	while(k >= 1){
		//printf("F0\n");
		b=1;
		while(b!=0){
			//printf("F1\n");
			b=0;
			for (i = k; i <=n-1;i++){
				//printf("\tA[%d] = %d < A[%d] = %d \n",i-k,A[i-k],i,A[i]);
				if(A[i-k] > A[i]){
					temp = A[i];
					A[i] = A[i-k];
					A[i-k] = temp;
					b++;
				}
			}
		}
		k=trunc(k/2);
	}
	/* Fin del alfortmo */
	/* Finaliza medicion de tiempo */
	uswtime(&utime1, &stime1, &wtime1);


	//Imprime arreglo ordenado
	/*
	for(i=0;i<n;i++)
		printf("%d\n",A[i]);
	*/
	//Libera el arreglo
	free(A);

	/* Imprime tiempos */
	//Cálculo del tiempo de ejecución del programa
	printf("Prueba con numero = %d\n",n);
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	exit(0);
}