typedef struct node* list;

list criaLista();
int listaVazia(list *lst);
int insereOrd(list *lst, int elem);
int removeOrd(list *lst, int elem);
int tamanhoLista(list *lst);
int limpaLista(list *lst);
int getElem(list *lst, int pos, int *out);
int removePos(list *lst, int pos, int *out);