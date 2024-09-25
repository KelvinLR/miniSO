#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SO.h"

int main(){
	t_SO *SO=SO_Create();
printf("==================================\n");
	SO_Gerar_Processo(SO,3,5);
	SO_Gerar_Processo(SO,5,2);
	SO_Gerar_Processo(SO,1,1);
printf("==================================\n");
printf("==================================\n");
	SO_Encerrar_Processo(SO);
	SO_Print(*SO);
	return 0;
}

