typedef struct nodo{
	char string[20];
	struct nodo *e, *d;
	int peso;
} *tree,Nodo;


int alt(tree t);
int max(int l, int r);
void delete(tree t);
tree rl(tree t);
tree rr(tree t);
tree drl(tree t);
tree drr(tree t);
void imprimeavl(tree t);
tree inserir(tree t, char s[]);
int existe(tree t,char s[]);
