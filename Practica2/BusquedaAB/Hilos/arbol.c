#include "arbol.h"
#include "funciones.h"
void insertarNodo(arbol *nodo, int num){
	//Primer caso, arbol vacío
	if(*nodo==NULL){
		*nodo=malloc(sizeof(Arbol));
		if (*nodo!=NULL){
			(*nodo)->valor=num;
			(*nodo)->izquierdo=NULL;
			(*nodo)->derecho=NULL;
		}else{
			printf("No hay memoria disponible :(\n");
		}
	//Arbol no vacio
	}else{
		if((*nodo)->valor>num){
			insertarNodo(&((*nodo)->izquierdo),num);
		}else if((*nodo)->valor<num){
			insertarNodo(&((*nodo)->derecho),num);
		}
	}
}
//Función que realiza el recorrido en inorden del arbol, regresa un entero el cual es el indice
//sobre el que se debe guargar el valor obtenido en el arreglo
int inOrden(arbol nodo,int *array,int indice){
	//Si existe un nodo entonces lo recorremos
	//La variable indice nos indica en donde guardar dentro del array
	if(nodo!=NULL){
		indice=inOrden(nodo->izquierdo,array,indice);
		//printf("%d\n", nodo->valor);
		array[indice]=nodo->valor;
		indice++;
		indice=inOrden(nodo->derecho,array,indice);
	}
	return indice;
}
//Método que permite realizar la búsqueda en el un arbol
//Se reciben como parámetros el arbol en el que se buscará y el valor que se buscará
int busquedaArbol(arbol nodo, int valor_buscar){
	//No existe el nodo, no se encontro el valor
	if(nodo==NULL){
		return 0;
	}else{
		//Si el valor del nodo actual es igual al valor buscado retornamos 1
		if (nodo->valor==valor_buscar){
			return 1;
		}else{
			//Si no, entonces comparamos el valor a buscar con el valor del nodo para saber hacia que lado ir
			if(valor_buscar>nodo->valor){
				return busquedaArbol(nodo->derecho, valor_buscar);
			}else{
				return busquedaArbol(nodo->izquierdo, valor_buscar);
			}
		}
	}
}