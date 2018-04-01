#ifndef __ARBOL_H__
#define __ARBOL_H__
	//Estrutura del árbol y funciones
	struct Arbol{
		int valor;
		struct Arbol *izquierdo;
		struct Arbol *derecho;
	};
	typedef struct Arbol Arbol;
	typedef Arbol *arbol;
	//Funciones
	//Función que permite insertar un nodo
	void insertarNodo(arbol *,int);
	//Función que permite recorrer el árbol en inorden
	int inOrden(arbol,int*,int);
	//Busca un arbol dentro del arbol
	int busquedaArbol(arbol, int);
#endif