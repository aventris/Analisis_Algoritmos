#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "tiempo.h"

void Hilos(int,int);
void* busquedaBinaria(void*);
int *array;
int A;
int tam;

void main(int argc,char *argv[]){
	/* Obtencion del arreglo de numeros */
	tam = atoi(argv[1]);

	printf("\n\n******************************************************\n");
	printf("******************************************************\n");
	printf("Tamanio de arreglo : %d\n", tam);
	printf("******************************************************\n");
	printf("******************************************************\n\n");
	array = (int*)malloc(tam*sizeof(int));
	for(int i=0;i<tam;i++)
		scanf("%d",&array[i]);

	/* Numero a buscar */
	int A[]={322486, 14700764, 3128036, 6337399, 61396,
		10393545, 2147445644, 1295390003, 450057883, 187645041,
		1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
		1360839354, 2109248666 , 2147470852, 0};
	for(int i = 0 ; i<21;i++){
		printf("Numero a buscar: %-13d\n",A[i]);
		Hilos(atoi(argv[2]),A[i]);
	}
	free(array);
}

void Hilos(int numHilos,int dato){
	/* Variables para los hilos */
	 // numHilos Numero de hilos
	int Tareas=tam/numHilos; // Tamanio de arreglo por hilo
	int Extra=tam%numHilos; // Carga extra para el ultimo hilo
	pthread_t *hilo = (pthread_t*)malloc(numHilos*sizeof(pthread_t));
	int lineasHilo[numHilos][3];
	/* Variables para medir tiempo */

	double utime0, stime0, wtime0,utime1, stime1, wtime1;
	/* Variablo que almacenara lo que se obtendra del hilo */
	int resultado = -1;
	for(int i=1;i<=numHilos;i++){
		/** Revisa si un hilo tendra que hacer mas lineas que los demas **/
		/** Llena arreglo **/
		if(i==numHilos&&Extra!=0){
			lineasHilo[i][0]=Tareas*(i-1);
			lineasHilo[i][1]=(Tareas*i)-1+Extra;
			lineasHilo[i][2]=dato;
		}
		else{
			lineasHilo[i][0]=Tareas*(i-1);
			lineasHilo[i][1]=(Tareas*i)-1;
			lineasHilo[i][2]=dato;
		}
		/** Luego de llenar la estrucura crea el hilo de la funcion de multiplicar matrices **/
		//printf("Line: %d fin: %d i: %d\n",lineasHilo[i][0],lineasHilo[i][1],i);
		pthread_create(&hilo[i-1],NULL,busquedaBinaria,(void *)&lineasHilo[i]);
	}
	
	void *status;
	uswtime(&utime0, &stime0, &wtime0);
	for(int i=0;i<numHilos;i++){
		pthread_join(hilo[i],&status);
		if((int)status!=-1)
			resultado = (int)status;
	}
	uswtime(&utime1, &stime1, &wtime1);
	if(resultado != -1)
		printf("Dato encontrado en la posicion [%d] del arreglo",resultado+1);
	else
		printf("No se encontro el dato");
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	free(hilo);

}

void* busquedaBinaria(void * lineasHiloR){
	/* Declaracion de variables para el agoritmo */
	int *lineasHilo=(int*)lineasHiloR; 
	int centro;
	int inferior=lineasHilo[0];
	int superior=lineasHilo[1];
	int dato=lineasHilo[2];
	//printf("Inferior: %d  Superior: %d\n",inferior,superior);
	/* Inicio de algoritmo*/
	while(inferior <= superior){
		centro = trunc((inferior+superior)/2);
		if(dato == array[centro])
			return (void *)centro; // Regresa posicion del dato enccontrado
		else if(dato<array[centro]) 
			superior=centro-1; // 
		else if(dato>array[centro])
			inferior = centro+1;
	}
	return (void *)-1;	//	No se encontro el dato

	/* Fin de algritmo */
}
//./a.out 100  236 2 < Numeros_Ordenados.txt