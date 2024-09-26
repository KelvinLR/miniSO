#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "processos.h"

t_Processo *processo_Create(int cod_processo, process_type tipo_processo,int ciclos){
	//alocar memoria para novo processo
	t_Processo *newProcesso=malloc(sizeof(t_Processo));
	if (newProcesso == NULL) {
		fprintf(stderr, "Alocação mal-sucedida");
	}

	//criando processo
	newProcesso->cod_processo=cod_processo;
	newProcesso->tipo_processo=tipo_processo;
	newProcesso->ciclos=ciclos;
	printf("proceso criado com sucesso\n");
	return newProcesso;
}

void processso_Dump(t_Processo processo){
	//printar processo
	printf("Codigo do processo: %i\n", processo.cod_processo);

	switch(processo.tipo_processo) {
		case IO_bound:
			printf("Tipo: I/O bound\n");
			break;
		case CPU_bound:
			printf("Tipo: CPU bound\n");
			break;
		case ideal_process:
			printf("Tipo: Processo ideal\n");
			break;
		default:
			printf("Tipo inválido\n");
			break;
	}

    printf("Ciclos: %d\n", processo.ciclos);
}
