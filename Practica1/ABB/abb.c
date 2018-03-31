#include"funciones.h"
int main(int argc, char const *argv[]){
	//Variables
	int i,j,temp,n,*array, indice;
	arbol nodoRaiz=NULL;  
	//Otenemos n, que es el tamaño del arreglo
	n = atoi(argv[1]);
	//printf("Tamanio: %d\n",n);
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
	//ABB
	//Insertamos los elementos del arreglo en el arbol
	for (i = 0; i < n; i++){
		insertarNodo(&nodoRaiz,array[i]);
	}
	//Realizamos el recorrido inorden del árbol y lo guardamos en el array
	//El 0 es por el indice en que debe ser almacenado el primer elemento leido del arbol en el array
	inOrden(nodoRaiz,array,0);
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	//Impresión array ordenado
	/*for (i = 0; i < n; i++){
		printf("%d\n", array[i]);
	}*/
	/*Liberar memoria */
	free(array);
	//Cálculo del tiempo de ejecución del programa
	printf("Prueba con %d numeros\n",n );
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