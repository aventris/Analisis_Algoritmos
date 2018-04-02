#include "funciones.h"

/*322486, 14700764, 3128036, 6337399, 61396,
10393545, 2147445644, 1295390003, 450057883, 187645041,
1980098116, 152503, 5000, 1493283650, 214826, 1843349527,
1360839354, 2109248666 , 2147470852 y 0*/

int main(int argc, char const *argv[]){

	int n = atoi(argv[1]),dato = atoi(argv[2]),i;
	int *A = (int*)malloc(sizeof(int)*n);
	A = arreglo(n);
	printf("n = %d\t dato = %d\n",n,dato);
	//BUSQUEDA LINEAL sin centinela
	for(i = 0; i < n; i++){
		if(A[i] == dato){
			printf("\tDato encontrado!!!!!!!!!!!!!!!!!\n");
			printf("A[%d] %d = %d\n",i,A[i],dato );
			break;
		}
	}
	printf("fin de BUSQUEDA\n");
	return 0;
}