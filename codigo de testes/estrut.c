#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "estrut.h"

int alt(tree t){
	if(t==NULL)
		return -1;
	else return t->peso;
}

int max(int l, int r){
	if(l>r) return l;
	else return r;
}

void delete(tree t){
	if(t!=NULL){
		delete(t->e);
		delete(t->d);
		free(t);
	}
}
//rotate left
tree rl(tree t){
	tree aux;
	aux=t->e;
	t->e=aux->d;
	aux->d=t;
	t->peso=max(alt(t->e),alt(t->d))+1;
	aux->peso=max(alt(aux->e),t->peso)+1;
	return aux;
}
//rotate right
tree rr(tree t){
	tree aux;
	aux=t->d;
	t->d=aux->e;
	aux->e=t;
	t->peso=max(alt(t->e),alt(t->d))+1;
	aux->peso=max(alt(aux->d),t->peso)+1;
	return aux;
}
//dupla rotacao esquerda
tree drl(tree t){
	t->e=rr(t->e);
	return rl(t);
}
//dupla rotacao direita
tree drr(tree t){
	t->d=rl(t->d);
	return rr(t);
}

void imprimeavl(tree t){
	if (t==NULL){
		printf("NULL\n");
		return;
	}
	printf("raiz: %s\n",t->string);
	if(t->e!=NULL) printf("esquerda: %s\n", t->e->string);
	else printf("NULL\n");
	if(t->d!=NULL) printf("direita:%s\n", t->d->string);
	else printf("NULL\n");
	printf("-------------\n");
	imprimeavl(t->e);
	printf("-------------\n");
	imprimeavl(t->d);

}

int existe(tree t, char s[]){
	if (t==NULL) return 0;
	else if (strcmp(s,t->string)==0) return 1;
	else if (strcmp(s,t->string)<0) return (existe(t->e,s));
	else return (existe(t->d,s));
}

tree inserir(tree t, char s[]){
	if (t==NULL){
		t=(tree) malloc(sizeof(Nodo));
		if(t==NULL){
			printf("Rebentou\n");
			exit(1);
		}
		else{
			strncpy(t->string,s,strlen(s));
			t->peso=0;
			t->e=t->d=NULL;
		}
	}
	else if(strcmp(s,t->string)<0){
		t->e=inserir(t->e,s);
		if(alt(t->e)-alt(t->d)==2){
			if(strcmp(s,t->e->string)<0) t=rl(t);
			else t=drl(t);
		}
	}
	else if(strcmp(s,t->string)>0){
		t->d=inserir(t->d,s);
		if (alt(t->d)-alt(t->e)==2){
			if (strcmp(s,t->d->string)>0) t=rr(t);
			else t=drr(t);
		}
	}	
	t->peso=max(alt(t->e),alt(t->d))+1;
	return t;
}
