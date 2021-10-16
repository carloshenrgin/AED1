typedef struct bebidas bebida;
typedef struct lista* list;

list criaLista();
int listaVazia(list lst);
int listaCheia(list lst);
int insereOrd(list lst, char nome[], int vol, float preco);
int removeOrd(list lst, char nome[], int vol, float preco);
void getElem(list lst, int pos);
int limpaLista(list lst);
int tamanhoLista(list lst);