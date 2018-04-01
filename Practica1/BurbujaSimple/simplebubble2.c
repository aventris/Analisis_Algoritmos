/*Burbuja simple*/
#include "funciones.h"
int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	int *A = (int *)malloc(sizeof(int)*n);
	int j,i,aux;
	//printf("%i\n",n);
	A = arreglo(n);
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	/*Simple bubble method*/
	for(i = 0; i < (n-2);i++){
		for(j = 0; j <= (n-2)-i;j++){
			if(A[j] > A[j+1]){
				aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
			}
		}
	}
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	/*Impresion de numeros
	//printf("\n*******************************************Numeros ordenados\n\n\n");
	for(i = 0; i < n;i++)
		fprintf(stdout,"%d\n",A[i]);
	*/
	free(A);
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
