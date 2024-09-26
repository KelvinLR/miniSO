#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include "processos.h"
#include "SO.h"

int main(){
	t_SO *SO=SO_Create();
	int opc, type, cycles;
	int code = 0;

	setlocale(LC_ALL, "Portuguese");

	do {
		printf("ESCOLHA UMA OPÇÃO\n");
		printf("1: Gerar processo\n");
		printf("2: Verificar S.O\n");
		printf("3: Encerrar ciclo do processo\n");
		printf("0: Sair\n");
		scanf("%i", &opc);

		switch(opc) {
			case 1: 
				system("cls");
				printf("Escolha o tipo de processo\n");
				printf("1: I/O bound\n");
				printf("2: CPU bound\n");
				printf("3: Processo Ideal\n");
				scanf("%i", &type);
				printf("Digite a quantidade de ciclos necessários\n");
				scanf("%i", &cycles);
				system("cls");
				SO_Gerar_Processo(SO, code, type, cycles);
				code++;
				break;
			case 2:
				system("cls");
				SO_Print(*SO);
				break;
			case 3:
				system("cls");
				SO_Encerrar_Processo(SO);
				break;
			case 0: 
				printf("Até mais");
				break;
			default:
				printf("Opção inválida");
				break;
		} 
		
	} while (opc != 0);
	
	return 0;
}

