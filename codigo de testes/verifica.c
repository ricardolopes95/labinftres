#include <stdio.h>
#include <string.h>
#include <ctype.h>


int verificaCliente (char* s) {
int i, r=1;					// ==0 False  !=0 True
	
	for (i=0;i<2;i++){
			if (isalpha(s[i])==0) {
				r=0;
				break;		
			}	
	}
	for (i=2;r!=0 && i<5;i++){
			if (isdigit(s[i])==0){  										//The isdigit() function shall return non-zero if c is a decimal digit; otherwise, it shall return 0
				r=0;
				break;
			}
	}
if (s[5]=='\0' && r==1) return 1;

return 0;
}

int verificaProduto (char* s){
int i , r=1;

for (i=0;i<2;i++){
		if ( isalpha(s[i]==0) ){
			r=0;
			break;
		}
}
	for (i=2;r!=0 && i<6;i++){
		if (isdigit(s[i])==0){  										//The isdigit() function shall return non-zero if c is a decimal digit; otherwise, it shall return 0
			r=0;
			break;
			}
	}
if (s[6]=='\0' && r==1) return 1;
return 0;
}

int main () {
int res=-1;
char s1[5];
char s2[6];

scanf ("%s",s1);
printf("verificaCliente: %d\n",verificaCliente(s1));
scanf ("%s",s2);
printf("verificaProduto: %d\n",verificaProduto(s2));




return 0;	
}


/*

Clientes
2 letras e 3 numeros

Produtos 
2 letras e 4 numeros 
*/