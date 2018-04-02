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
	//Creamos un arreglo dinámico para guardar el arreglo
	array = (int*)malloc(n*sizeof(int));
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
	//Identificadores hilos
	pthread_t h[num_hilos];
	//Imprimir información
	puts("*******************************************************************************\n");
	printf("Pruebas con n=%d\n\n",n);
	//Realizamos el recorrido inorden del árbol y lo guardamos en el array
	//El 0 es por el indice en que debe ser almacenado el primer elemento leido del arbol en el array
	//inOrden(nodoRaiz,array,0);
	/*Liberar memoria */
	//free(array);
	struct parametros p;
	void *retorno;
	int resultado;
	//Se realiza la busqueda de cada elemento y se muestran los tiempos por cada uno
	for(i=0;i<20;i++){
		resultado=0;
		printf("---------------------------\n");
		printf("Número a buscar:%d\n",A[i]);
		p.valor_buscar=A[i];
		//******************************************************************
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************
		uswtime(&utime0, &stime0, &wtime0);
		//Creamos los hilos
		for(j=0;j<num_hilos;j++){
			p.nodo=nodoRaiz[j];
			pthread_create (&h[j], NULL , busquedaA , (void*)&p);
		}
		//Esperamos que los hilos terminen y verificamos que obtuvieron
		for(j=0;j<num_hilos;j++){
			pthread_join(h[j],&retorno);
			if((int)retorno==1){
				resultado=1;
			}
		}
		//Evaluar los tiempos de ejecución 
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);
		printf("Encontrado: %d\n",resultado);
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
//Función que ejecuta cada hilo, se recibe el arbol con el que se trabajará y el valor a buscar, regresa un 0 o 1
void *busquedaA(void *p){
	struct parametros *p1=(struct parametros*)p;
	//Método para realizar la búsqueda, el método devuelve un 1 se el valor fue encontrado, o un 0 si no
	return (void*)busquedaArbol(p1->nodo,p1->valor_buscar);
}