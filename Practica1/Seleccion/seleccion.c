/*Burbuja simple*/
#include "funciones.h"
int main(int argc, char const *argv[])
{

	//Se creara solo la memoria necesaria para los numeros en
	//los argumentos argc 
	int *A,n = atoi(argv[1]);
	A = (int *)malloc(sizeof(int)*n);
	int i,k,p;
	int temp;
	A = arreglo(n);
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	/*selection sort method*/
	for(k = 0; k < (n-2); k++){
		p = k;
		for(i = k+1; i <= (n-1);i++){
			if(A[i] < A[p]){
				p = i;
			}
		}
		temp = A[p];
		A[p] = A[k];
		A[k] = temp;
	}
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	/*Numeros ordenados
	//printf("\nNumeros ordenados\n");
	for(i = 0; i < n;i++)
		fprintf(stdout,"%d\n",A[i]);
	*/
	free(A);
	//Cálculo del tiempo de ejecución del programa
	printf("Prueba con %d numeros\n",n );
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	return 0;
}