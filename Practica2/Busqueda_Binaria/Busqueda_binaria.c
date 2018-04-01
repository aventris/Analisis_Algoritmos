#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"
int busquedaBinaria(int*,int,int);


void main(int argc,char *argv[]){
	/* Obtencion del arreglo de numeros */
	int tam = atoi(argv[1]);


	printf("\n\n******************************************************\n");
	printf("******************************************************\n");
	printf("Tamanio de arreglo : %d\n", tam);
	printf("******************************************************\n");
	printf("******************************************************\n\n");

	int *array = (int*)malloc(tam*sizeof(int));
	for(int i=0;i<tam;i++)
		scanf("%d",&array[i]);

	int A[]={322486, 14700764, 3128036, 6337399, 61396,
		10393545, 2147445644, 1295390003, 450057883, 187645041,
		1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
		1360839354, 2109248666 , 2147470852, 0};
	for(int i = 0 ; i<21;i++){
		printf("Buscando numero : %d\n",A[i] );
		double utime0, stime0, wtime0,utime1, stime1, wtime1;
		uswtime(&utime0, &stime0, &wtime0);
		int resultado = busquedaBinaria(array,A[i],tam);
		uswtime(&utime1, &stime1, &wtime1);

		if(resultado!=-1)
			printf("Encontrado en la posicion  [%d] del arreglo",resultado+1);
		else
			printf("No encontrado");
		uswtime(&utime1, &stime1, &wtime1);
		//Cálculo del tiempo de ejecución del programa
		printf("\n");
		printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
		printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
	}
	free(array);	
	
}

int busquedaBinaria(int *array,int dato,int tam){
	/* Declaracion de variables para el agoritmo */
	int centro;
	int inferior=0;
	int superior=tam-1;
	/* Inicio de algoritmo*/
	while(inferior <= superior){
		centro = trunc((inferior+superior)/2);
		//printf("Centro : %d  Bucando: %d  Actual: %d\n",centro,dato,array[centro]);
		if(dato == array[centro])
			return centro; // Regresa posicion del dato enccontrado
		else if(dato<array[centro]) 
			superior=centro-1; // 
		else if(dato>array[centro])
			inferior = centro+1;
	}
	return -1;	//	No se encontro el dato

	/* Fin de algritmo */
}

//./a.out 10000000 322486 < Numeros_Ordenados.txt 