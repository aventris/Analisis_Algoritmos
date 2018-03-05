#include <stdio.h>
#include <stdlib.h>
int *arreglo(int n){
	int i;
	int *A;
	A = (int *)malloc(sizeof(int)*n);
	if(A!= NULL){
		for(i = 0; i < n; i++){
			scanf("%d",&A[i]);
		}
	}
	return A;
}