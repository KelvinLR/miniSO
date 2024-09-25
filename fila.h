#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "element.h"


#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;
//STRUCT FILA
typedef struct fila{
	t_Element *rootElement;
	t_Element *currentElement;
	int numElement;
}t_Fila;
//FUNCOES FILA
	//criar fila
t_Fila *fila_create();
	//confere se elemento raiz da fila é NULL
BOOL fila_Is_Root_Element_Null(t_Fila *fila);
	//confere  se elemento current da fila é NULL
BOOL fila_Is_Current_Element_Null(t_Fila *fila);
	//confere se numero de elementos da fila é zero
BOOL fila_Is_Num_Element_Zero(t_Fila *fila);

	//retorna elemento root da fila
t_Element *fila_Get_Root_Element(t_Fila *fila);
	//retorna elemento current da fila
t_Element *fila_Get_Current_Element(t_Fila *fila);
	//retorna tamanho da fila
int fila_Get_Num_Element(t_Fila *fila);
	
	//elemento current aponta para prox elemento
void fila_Go_Prox_Element(t_Fila *fila);
	//elemento current aponta para prev elemento
void fila_Go_Prev_Element(t_Fila *fila);
	//elemento current aponta para último elemento da fila
void fila_Go_Last_Element(t_Fila *fila);
	//elemento current aponta para o root elemento da fila
void fila_Go_To_Root_Element(t_Fila *fila);
	//elemento current aponta para penultimo elemento da fila
void fila_Go_Penultimate_Element(t_Fila *fila);

	//alocar elemento na fila
void fila_Alocate_Element(t_Fila *fila,void *data,int sizeData);
	//desalocar elemento fila
void fila_Desalocate_Element(t_Fila *fila);

	//printar fila
void fila_Dump(t_Fila *fila);

//===============================================================
t_Fila *fila_create(){
	t_Fila *new_Fila;
	//confere se alocação da fila ocorreu bem
	if((new_Fila=malloc(sizeof(t_Fila)))==NULL){
		printf("falha ao alocar fila\n");
		return NULL;
	}
	//criar fila
	new_Fila->rootElement=NULL;
	new_Fila->currentElement=new_Fila->rootElement;
	new_Fila->numElement=0;
	printf("Fila criada com sucesso\n");
	return new_Fila;
	
}
//===============================================================
BOOL fila_Is_Root_Element_Null(t_Fila *fila){
	//confere se elemento root é NULL
	if(fila->rootElement==NULL){
		return TRUE;
	}
		return FALSE;
}
//===============================================================
BOOL fila_Is_Current_Element_Null(t_Fila *fila){
	//confere se elemento current é NULL
		if(fila->currentElement==NULL){
		return TRUE;
	}
		return FALSE;

}
//===============================================================
BOOL fila_Is_Num_Element_Zero(t_Fila *fila){
	//confere se o numero de elementos da fila é zero
		if(fila->numElement==0){
		return TRUE;
	}
		return FALSE;
}
//===============================================================
t_Element *fila_Get_Root_Element(t_Fila *fila){
	//confere se elemento root da fila é igual a NULL
	if(fila_Is_Root_Element_Null(fila)){
		printf("Elemento root é NULL\n");
		return NULL;
	}
	//retorna elemento root da fila
	return fila->rootElement;
}
//===============================================================
t_Element *fila_Get_Current_Element(t_Fila *fila){
	//confere se elemento current da fila é NULL
	if(fila_Is_Current_Element_Null(fila)){
		printf("Elemento current  é NULL\n");
		return NULL;
	}
	//retorna elemento current da fila
	return fila->currentElement;
}
//===============================================================
int fila_Get_Num_Element(t_Fila *fila){
	//confere se o numero de elementos da lista é igual a zero
	if(fila_Is_Num_Element_Zero(fila)){
		printf("numero de elementos é igual a ZERO\n");
		return 0;
	}
	//retorna numero de elementos da fila
		return fila->numElement;
}
/////////////////////////////////////////////////////////////////
//===============================================================
void fila_Go_Prox_Element(t_Fila *fila){
	//elemento current da fila aponta para o proximo elemento
	fila->currentElement=get_Prox_Element(fila_Get_Current_Element(fila));
	return;
}
//===============================================================
void fila_Go_Prev_Element(t_Fila *fila){
	//elemento current da fila aponta para o prev elemento
	fila->currentElement=get_Prev_Element(fila_Get_Current_Element(fila));
	return;
}
//===============================================================
void fila_Go_Last_Element(t_Fila *fila){
	//elemento current da fila aponta para o último elemento
	if(fila_Is_Num_Element_Zero(fila)){
		printf("fila esta vazia\n");
		return;
	}
	//elemento current aponta para elemento root
	fila_Go_To_Root_Element(fila);
	//loop até chegar ao último elemento da fila
	int i;
	for(i=1;i<fila_Get_Num_Element(fila);i++){
		fila_Go_Prox_Element(fila);
	}
	return;
}
//===============================================================
void fila_Go_Penultimate_Element(t_Fila *fila){
	//elemento current vai para o último elemento da fila
	fila_Go_Last_Element(fila);
	//elemento current aponta para o prev elemento
	fila_Go_Prev_Element(fila);
}
//===============================================================
void fila_Go_To_Root_Element(t_Fila *fila){
	//elemento current aponta para o root elemento
	fila->currentElement=fila->rootElement;
	return;
}
//===============================================================
void fila_Alocate_Element(t_Fila *fila,void *data,int sizeData){
	//confere se o endereço do dado passado como parametro é NULL
	if(data==NULL){
		printf("elemento NULL\n");	
		return;

	}
	//confere se fila é NULL
	if(fila==NULL){
		printf("fila NULL\n");	
		return;

	}
	//confere se a fila está vazia
	if(fila_Is_Num_Element_Zero(fila)){
		//cria novo elemento e elemento root aponta para elemento criado
		fila->rootElement=element_Create(data,sizeData);
		//incrementa número de elementos da fila
		(fila->numElement)++;
		printf("elemento alocado com sucesso\n");
		printf("=============================\n");
		return;
	}
	//elemento current aponta para último elemento
	fila_Go_Last_Element(fila);
	t_Element *current=fila_Get_Current_Element(fila);
	//próximo elemento do elemento current aponta para novo elemento criado
	current->prox_Element=element_Create(data,sizeData);
	//elemento prev do novo elemento aponta para elemento current
	current->prox_Element->prev_Element=current;
	//incrementa número de elementos da fila
	(fila->numElement)++;
	printf("elemento alocado com sucesso\n");
	printf("=============================\n");
	return;
}
//===============================================================
void fila_Desalocate_Element(t_Fila *fila){
	//elemento current aponta para elemento root
	fila_Go_To_Root_Element(fila);
	//elemento auxiliar para deletar antigo elemento root
	t_Element *elementToDelete=fila_Get_Current_Element(fila);
	//elemento current aponta para prox elemento
	fila_Go_Prox_Element(fila);
	//elemento root da fila aponta para elemento current
	fila->rootElement=fila_Get_Current_Element(fila);
	//antigo elemento root é deletado
	delete_Element(elementToDelete);
	//elemento auxiliar para tornar elemento prev do novo elemento root igual a NULL
	t_Element *rootElement=fila_Get_Current_Element(fila);
	rootElement->prev_Element=NULL;
	//decrementa numero de elementos na fila
	fila->numElement--;
	return;

}
//===============================================================
void fila_Dump(t_Fila *fila){
	printf("==========================================\n");
	int i;
	//elemento current aponta para elemento root da fila
	fila_Go_To_Root_Element(fila);
	//loop para printar fila por completo
	for(i=0;i<fila_Get_Num_Element(fila);i++){
		dump_Element(fila_Get_Current_Element(fila));
		fila_Go_Prox_Element(fila);
	}
	return;
}

