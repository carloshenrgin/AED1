typedef struct node* list;

list criaLista();
int listaVazia(list *lst);
int insereOrd(list *lst, int elem);
int removeElem(list *lst, int elem);
int obtemValor(list *lst, int *output, int pos);