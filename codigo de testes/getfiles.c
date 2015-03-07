#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estrut.h"


int validecode(char file[],char code[]){
	int i=0;
	if (strcmp(file,"FichClientes.txt")==0){
		for(i=0;i<2;i++){
			if (!(code[i]>='A'&& code[i]<='Z')) return 0; 
		}
		for(i=2;i<5;i++){
			if (!(code[i]>='0'&& code[i]<='9')) return 0; 
		}
		return 1;
	}
	else if (strcmp(file,"FichProdutos.txt")==0){
		for(i=0;i<2;i++){
			if (!(code[i]>='A'&& code[i]<='Z')) return 0; 
		}
		for(i=2;i<6;i++){
			if (!(code[i]>='0'&& code[i]<='9')) return 0; 
		}
		return 1;
	}
	else return 1;
}


tree loadfile(char file[],tree t){
	int val=0, total=0;
	char code[40];
	FILE *d;
	d=fopen(file,"r");
	if (d!=NULL){
		while(fgets(code,40,d)!=NULL){
			code[strlen(code)-2]='\0';
			if (validecode(file,code)){
				t=inserir(t,code);
				val++;
			}
			total++;
		}
		printf("%s\n",code);
		fclose(d);
		printf("%s carregado com succeso, %d codigos validados %d codigos lidos\n",file,val,total);
	}
	else printf("Erro ao carregar o ficheiro %s\n",file);
	return t;
}


int main(){
	char c='a';
	int i=0;
	char file[20]="FichClientes.txt";
	char code[10];
	tree produtos=NULL;
	produtos=loadfile(file,produtos);
//	imprimeavl(produtos);
//	scanf("%s",code);
//	code[strlen(code)-1]='\0';
	while(c!='\n'){
		c=getchar();
		code[i]=c;
		i++;
	}
	code[i-1]='\0';
	printf("%s\n",code);
	printf("%d\n", existe(produtos,code));
	delete(produtos);
	return 0;
}
