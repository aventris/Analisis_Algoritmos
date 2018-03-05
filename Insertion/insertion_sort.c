//Este algoritmo es bueno para inputs de pocos elementos
#include "funciones.h"
int main(int argc, char const *argv[]){
	//Variables
	int i,j,temp,n,*array;
	//Otenemos n, que es el tamaño del arreglo
	n = atoi(argv[1]);
	printf("Tamanio: %d\n",n);
	//Creamos un arreglo dinámico para guardar el arreglo
	array = (int*)malloc(n*sizeof(int));
	//Obtenemos los valores del arreglo
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//Algoritmo Insertion sort
	//Se itera por cada elemento del arreglo menos 1 (el primero), 
	for (j = 1; j < n; j++){
		//Obtenemos el valor del elemento que vamos a comparar
		temp=array[j];
		//Las comparaciones se deben hacer con todos los elementos anteriores
		i=j-1;
		//Comparamos con todos los elementos anteriores, y nos continuamos moviendo hacia atras mientras el elemento sea mayor a temp,
		//En cada ocasión que se avanza hacia atras, recorremos hacia la derecha el valor con el que comparamos
		while(i>=0 && array[i]>temp){
			array[i+1]=array[i];
			i-=1;
		}
		//Insertamos el elemento en la posición que le corresponde
		array[i+1]=temp;
	}
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	//Impresión array ordenado
	for (i = 0; i < n; i++){
		printf("%d\n", array[i]);
	}
	/*Liberar memoria */
	free(array);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	return 0;
}