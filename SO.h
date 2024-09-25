#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "processos.h"

//STRUCT DE SISTEMA OPERACIONAL
typedef struct SO{
	t_Fila *filaProcessos;
	int numProcessos;
}t_SO;
//FUNCAO SISTEMA OPERACIONAL
	//funcao criar
t_SO *SO_Create();
	//funcao gerar procesos
void SO_Gerar_Processo(t_SO *SO,int nomeProcesso,int ciclos);
	//funcao encerrar processos
void SO_Encerrar_Processo(t_SO *SO);
	//funcao dump sistema operacional
void SO_Dump(t_SO SO);
	//funcao printar sistema operacional
void SO_Print(t_SO SO);
//=====================================================
t_SO *SO_Create(){
	t_SO *newSO;	
	//confere se SO é igual a NULL
	if((newSO=malloc(sizeof(t_SO)))==NULL){
		printf("falha ao criar SO\n");
		return NULL;
	}
	//gera fila do struct SO
	newSO->filaProcessos=fila_create();
	newSO->numProcessos=0;
	printf("Sistema operacional criado com sucesso\n");
	return newSO;
}
//=====================================================
void SO_Gerar_Processo(t_SO *SO,int nomeProcesso,int ciclos){
	//criando novo processo
	t_Processo *newProcesso=processo_Create(nomeProcesso,ciclos);
	int i;
	//loop que adiciona os processos de acordo com o numero de ciclos de cada processo
	for(i=0;i<ciclos;i++){
	fila_Alocate_Element(SO->filaProcessos,newProcesso,sizeof(t_Processo));
	}
	//incrementa numero de processos ativos no SO
	SO->numProcessos++;
	return;
}
//=====================================================
void SO_Encerrar_Processo(t_SO *SO){
	//encerra um ciclo de processo da fila do SO
	//elemento current da fila de processos aponta para o root
	fila_Go_To_Root_Element(SO->filaProcessos);
	//elemento auxiliar aponta para root
	t_Element *rootElement=fila_Get_Root_Element(SO->filaProcessos);
	//elemento current aponta para próximo elemento
	fila_Go_Prox_Element(SO->filaProcessos);
	//elemento auxiliar aponta para current
	t_Element *currentElement=fila_Get_Current_Element(SO->filaProcessos);
	//Compara, caso o elemento root seja igual ao proximo elemento após ele, não decrementa numero de processos
	//Caso elemento root seja diferente do próximo elemento após ele,decrementa numero de processos
	if((memcmp(get_Data_Element(rootElement),get_Data_Element(currentElement),get_Element_Size(rootElement)))!=0){
		SO->numProcessos--;
	printf("todos os ciclos de um processo foram encerrados\n");
	}
	//desaloca elemento da fila de processos
	fila_Desalocate_Element(SO->filaProcessos);
printf("////////////////////////////////////////////////////////////////////////\n");
	return;
}
//=====================================================
void SO_Dump(t_SO SO){
	//realiza o dump da fila
	fila_Dump(SO.filaProcessos);
	return;
}
//=====================================================
void SO_Print(t_SO SO){
	//elemento current da fila de processos aponta para root elemento
	fila_Go_To_Root_Element(SO.filaProcessos);
	int i;
	//loop para printar o SO
	for(i=0;i<fila_Get_Num_Element(SO.filaProcessos);i++){
		t_Element *current=fila_Get_Current_Element(SO.filaProcessos);
		t_Processo *processo=(t_Processo *)get_Data_Element(current);
		processso_Dump(*processo);
		fila_Go_Prox_Element(SO.filaProcessos);
	}
}
//=====================================================
