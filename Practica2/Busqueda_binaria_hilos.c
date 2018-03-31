#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

void* busquedaBinaria(void*);
int *array;
int dato;
int tam;

void main(int argc,char *argv[]){
	/* Obtencion del arreglo de numeros */
	tam = atoi(argv[1]);
	array = (int*)malloc(tam*sizeof(int));
	for(int i=0;i<tam;i++)
		scanf("%d",&array[i]);

	/* Numero a buscar */
	dato = atoi(argv[2]);
	/* Variables para los hilos */
	int numHilos = atoi(argv[3]); // Numero de hilos
	int Tareas=tam/numHilos; // Tamanio de arreglo por hilo
	int Extra=tam%numHilos; // Carga extra para el ultimo hilo
	pthread_t *hilo = (pthread_t*)malloc(numHilos*sizeof(pthread_t));
	int lineasHilo[numHilos][2];
	
	
	/* Variablo que almacenara lo que se obtendra del hilo */
	int resultado = -1;
	for(int i=1;i<=numHilos;i++){
		/** Revisa si un hilo tendra que hacer mas lineas que los demas **/
		/** Llena arreglo **/
		if(i==numHilos&&Extra!=0){
			lineasHilo[i][0]=Tareas*(i-1);
			lineasHilo[i][1]=(Tareas*i)-1+Extra;
		}
		else{
			lineasHilo[i][0]=Tareas*(i-1);
			lineasHilo[i][1]=(Tareas*i)-1;
		}
		/** Luego de llenar la estrucura crea el hilo de la funcion de multiplicar matrices **/
		//printf("Line: %d fin: %d i: %d\n",lineasHilo[i][0],lineasHilo[i][1],i);
		pthread_create(&hilo[i-1],NULL,busquedaBinaria,(void *)&lineasHilo[i]);
	}

	void *status;

	for(int i=0;i<numHilos;i++){
		pthread_join(hilo[i],&status);
		if((int)status!=-1)
			resultado = (int)status;
	}

	if(resultado != -1)
		printf("Dato encontrado en la posicion [%d] del arreglo\n",resultado);
	else
		printf("No se encontro el dato\n");

}

void* busquedaBinaria(void * lineasHiloR){
	/* Declaracion de variables para el agoritmo */
	int *lineasHilo=(int*)lineasHiloR; 
	int centro;
	int inferior=lineasHilo[0];
	int superior=lineasHilo[1];

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