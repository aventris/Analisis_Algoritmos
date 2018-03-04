//Este algoritmo es bueno para inputs de pocos elementos
#include"funciones.h"
int main(int argc, char const *argv[]){
	int array[5]={5,2,6,1,3};
	int i,j,valor;
	for (j = 1; j < SIZEARRAY(array); j++){
		valor=array[j];
		i=j-1;
		while(i>=0 && array[i]>valor){
			array[i+1]=array[i];
			i-=1;
		}
		array[i+1]=valor;
	}
	for (i = 0; i < SIZEARRAY(array); i++){
		printf("%d\n", array[i]);
	}
	return 0;
}

 ./a.out < archivo_a_leer >> archivo_de_salida