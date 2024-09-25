#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fila.h"
//STRUCT PROCESSO
typedef struct processo{
	int nomeProcesso;
	int ciclos;
}t_Processo;
//FUNCOES PROCESSOS
	//funcao criar processo
t_Processo *processo_Create(int nomeProcesso,int ciclos);
 	//funcao dump processo
void processso_Dump(t_Processo processo);



//=====================================================
t_Processo *processo_Create(int nomeProcesso,int ciclos){
	//alocar memoria para novo processo
	t_Processo *newProcesso=malloc(sizeof(t_Processo));
	//criando processo
	newProcesso->nomeProcesso=nomeProcesso;
	newProcesso->ciclos=ciclos;
	printf("proceso criado com sucesso\n");
	return newProcesso;
}
//=====================================================
void processso_Dump(t_Processo processo){
	//printar processo
	printf("nome do processo:\n");	
	printf("%d\n",processo.nomeProcesso);

	return;
}
//=====================================================



