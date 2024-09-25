#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila.h"


int main() {
	int x=12;
	t_Fila *fila=fila_create();
	fila_Alocate_Element(fila,&x,sizeof(int));
	 x=5;
	fila_Alocate_Element(fila,&x,sizeof(int));
	 x=10;
	fila_Alocate_Element(fila,&x,sizeof(int));

	fila_Desalocate_Element(fila);
	
	fila_Dump(fila);



	return 0;
}

