typedef struct bebidas bebida;
typedef struct lista* list;

list criaLista();
int listaVazia(list lst);
int listaCheia(list lst);
int insereElem(list lst, char frase[]);
int removeElem(list lst, char frase[]);
void getElem(list lst, int pos);
int limpaLista(list lst);
int tamanhoLista(list lst);