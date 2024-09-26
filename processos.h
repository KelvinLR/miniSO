#ifndef PROCESSOS_H
#define PROCESSOS_H

typedef enum process_type {
	IO_bound,
	CPU_bound,
	ideal_process,
} process_type;

//STRUCT PROCESSO
typedef struct processo {
	int cod_processo;
	process_type tipo_processo;
	int ciclos;
} t_Processo;

//FUNCOES PROCESSOS
t_Processo *processo_Create(int cod_processo, process_type tipo_processo, int ciclos);
void processso_Dump(t_Processo processo);

#endif
