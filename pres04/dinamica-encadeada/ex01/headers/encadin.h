typedef struct node* lista;

lista criaLista();
int listaVazia(lista *lst);
int listaCheia(lista *lst);
int insereElem(lista *lst, char item);
int removeElem(lista *lst, char item);
int obtemPos(lista *lst, int pos);
int limpaLista(lista *lst);