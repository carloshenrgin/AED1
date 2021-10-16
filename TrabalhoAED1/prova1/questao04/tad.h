typedef struct node* list;

list criaLista();
int listaVazia(list *lst);
int insereOrd(list *lst, float elem);
int getPosElem(list *lst, float elem, int *pos);
