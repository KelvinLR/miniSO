#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions_Show.h"

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;

//STRUCT ELEMENTO
typedef struct element{
	void   *data_Element;
	struct element *prox_Element;
	struct element *prev_Element;
	int    element_Size;
}t_Element;
//FUNCOES ELEMENTO 
	//funcao criar elemento
t_Element *element_Create(void *data,int size);
	//funcao deletar elemento 
void delete_Element(t_Element *element);
	//funcao retorna dado do endereço apontado pelo elemento
void *get_Data_Element(t_Element *element);
	 //funcao retorna endereço do prox elemento
t_Element *get_Prox_Element(t_Element *element);
	 //funcao retorna endereço do prev elemento
t_Element *get_Prev_Element(t_Element *element);
	//funcao retorna tamanho do dado apontado pelo elemento
int get_Element_Size(t_Element *element);
	//funcao confere e retorna se o endereço apontado pelo elemento é NULL
BOOL is_Null_Element(t_Element *element);
	//funcao para apontar para proximo elemento
t_Element *go_Next_Element(t_Element *element);
	//funcao para apontar para prev elemento
t_Element *go_Prev_Element(t_Element *element);
	//funcao dump elemento
void dump_Element(t_Element *element);

t_Element *element_Create(void *data,int size){
	t_Element *new_Element;
	//confere se alocação do elemento ocorreu bem	
	if((new_Element=malloc(sizeof(t_Element)))==NULL){
		printf("falha ao criar elemento\n");
		return NULL;
	}
	//confere se endereço para o qual o elemento aponta é igual a NULL
	if((new_Element->data_Element=malloc(size))==NULL){
		printf("falha ao criar elemento\n");
		return NULL;
	}
	//copia os dados do endereço do dado passado por parametro
	memcpy(new_Element->data_Element,data,size);
	new_Element->prox_Element=NULL;
	new_Element->prev_Element=NULL;
	new_Element->element_Size=size;
	printf("elemento criado com sucesso\n");
	return new_Element; 
}

void delete_Element(t_Element *element){
	//dá free no endereço apontado por elemento
	free(element->data_Element);
	//dá free no elemento
	free(element);
	printf("elemento deletado\n");
	return;
}

BOOL is_Null_Element(t_Element *element){
	//confere se o elemento é  null
	if(element==NULL){
		return TRUE;
	}
	return FALSE;
}

void *get_Data_Element(t_Element *element){
	//confere se o endereço para o qual elemento aponta é NULL, caso não,retorna endereço
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return NULL;
	}
	return element->data_Element;
	
}

t_Element *get_Prox_Element(t_Element *element){
	//confere se elemento é NULL
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return NULL;
	}
	//retorna o proximo endereço que elemento aponta
	return element->prox_Element;

}

t_Element *get_Prev_Element(t_Element *element){
	//confere se elemento é NULL
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return NULL;
	}
	//retorna prev endereço que elemento aponta
	return element->prev_Element;


}

int get_Element_Size(t_Element *element){
	//confere se elemento é igual a NULL
	if(is_Null_Element(element)){
		printf("elemento igual a null");
		return 0;
	}
	//retorna o tamanho do dado que elemento aponta
	return element->element_Size;
}

void dump_Element(t_Element *element){
	//confere se elemento é NULL
	if(is_Null_Element(element)){
		printf("falha ao printar elemento\n");
		return;
	}
	//realiza o dump do elemento
	printf("ENDEREÇO ELEMENTO:\n");
	addressDump(element);
	printf("DADOS ELEMENTO\n");
	dataDump(get_Data_Element(element),get_Element_Size(element));
	printf("ENDEREÇO ELEMENTO ANTERIOR:\n");
	addressDump(get_Prev_Element(element));
	printf("ENDEREÇO ELEMENTO POSTERIOR:\n");
	addressDump(get_Prox_Element(element));
	printf("=====================================================================\n");
	return ;

}

t_Element *go_Next_Element(t_Element *element){
	//elemento aponta para proximo elemento
	element=element->prox_Element;
	return element;
}

t_Element *go_Prev_Element(t_Element *element){
	//elemento aponta para prev elemento
	element=element->prev_Element;
	return element;
}



