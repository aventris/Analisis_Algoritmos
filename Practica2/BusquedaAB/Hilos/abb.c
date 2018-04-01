#include"funciones.h"
int main(int argc, char const *argv[]){
	//Variables
	int i,j,n,*array, num_hilos, elementos_hilo, valores_insertados;
	//Arreglo de número a buscar
	int A[]={322486, 14700764, 3128036, 6337399, 61396,
		10393545, 2147445644, 1295390003, 450057883, 187645041,
		1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
		1360839354, 2109248666 , 2147470852, 0};
	//Definimos el número de hilos
	num_hilos=4;
	//Un arbol por cada hilo
	arbol nodoRaiz[num_hilos];
	//Obtenemos n, que es el tamaño del arreglo
	n = atoi(argv[1]);
	//Definimos cuantos números quedarán por cada hilo
	elementos_hilo=n/num_hilos;
	//Identificadores hilos
	//VOY AQUÍIIIIIIIIIIIIIIIIIIIII,
	//TODO: Aquí tengo que generar un pthread_t en un for, me falta crear cada hilo y ejecutarlos
	//hacer join e imprimir tiempos
	pthread_t h1;
	pthread_t h2;
	pthread_t h3;
	pthread_t h4;

	pthread_create (&h1, NULL , hola , NULL );

	//Creamos un arreglo dinámico para guardar el arreglo
	array = (int*)malloc(elementos_hilo*sizeof(int));
	//Obtenemos los valores del arreglo
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	//Variable que ayuda a determinar cuantos valores han sido insertados
	valores_insertados=0;
	//Insertamos los elementos del arreglo en el arbol
	for(j=0;j<num_hilos;j++){
		nodoRaiz[j]=NULL;
		for (i = valores_insertados; i < valores_insertados+elementos_hilo; i++){
			insertarNodo(&nodoRaiz[j],array[i]);
		}
		valores_insertados+=elementos_hilo;
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
		printf("---------------------------\n");
		printf("Número a buscar:%d\n",A[i]);
		//******************************************************************	
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		uswtime(&utime0, &stime0, &wtime0);
		//Método para realizar la búsqueda, el método devuelve un 1 se el valor fue encontrado, o un 0 si no
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

void *busquedaA(void *parametros){

}