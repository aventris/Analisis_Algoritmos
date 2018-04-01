#include"funciones.h"
int main(int argc, char const *argv[]){
	//Variables
	int i,n,*array;
	//Arreglo de número a buscar
	int A[]={322486, 14700764, 3128036, 6337399, 61396,
		10393545, 2147445644, 1295390003, 450057883, 187645041,
		1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
		1360839354, 2109248666 , 2147470852, 0};
	arbol nodoRaiz=NULL;  
	//Obtenemos n, que es el tamaño del arreglo
	n = atoi(argv[1]);
	//printf("n= %d\n",n);
	//Creamos un arreglo dinámico para guardar el arreglo
	array = (int*)malloc(n*sizeof(int));
	//Obtenemos los valores del arreglo
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	//ABB
	//Insertamos los elementos del arreglo en el arbol
	for (i = 0; i < n; i++){
		insertarNodo(&nodoRaiz,array[i]);
	}

	//Imprimir información
	puts("*******************************************************************************\n");
	printf("Pruebas con %d numeros\n\n",n);
	//Realizamos el recorrido inorden del árbol y lo guardamos en el array
	//El 0 es por el indice en que debe ser almacenado el primer elemento leido del arbol en el array
	//inOrden(nodoRaiz,array,0);
	/*Liberar memoria */
	free(array);
	//Se realiza la busqueda de cada elemento y se muestran los tiempos por cada uno
	for(i=0;i<20;i++){
		//Método para realizar la búsqueda, el método devuelve un 1 se el valor fue encontrado, o un 0 si no
		printf("---------------------------\n");
		printf("Número a buscar:%d\n",A[i]);
		//******************************************************************	
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		uswtime(&utime0, &stime0, &wtime0);
		printf("¿Encontrado?:%d\n",busquedaArbol(nodoRaiz, A[i]));
		//Evaluar los tiempos de ejecución 
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);
		//Impresión array ordenado
		/*for (i = 0; i < n; i++){
			printf("%d\n", array[i]);
		}*/
		//Cálculo del tiempo de ejecución del programa
		printf("\n");
		printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
		printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
		//******************************************************************
	}
	puts("\n\n\n");
	return 0;
}