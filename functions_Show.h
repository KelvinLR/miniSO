#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOL;

void addressDump(void *address);
void dataDump(void *address,int size);

void dataDump(void *address,int size){
	int i;
	for (i=0;i<size;i++){
		printf("%x ",*(unsigned char *)(address+i) ); 
	}
	printf("\n");
}

void addressDump(void *address){
	if(address==NULL){
		printf("NULL\n");
		return;
	}
	int i;
	for(i=0;i<8;i++){
		printf("%x ",(unsigned char *)(address+i));	
	}
	printf("\n");
}

 
