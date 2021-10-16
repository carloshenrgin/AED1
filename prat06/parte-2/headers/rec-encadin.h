typedef struct node* list;

list criaLista();
int listaVazia(list *lst);
int insereOrd(list *lst, double input);
int removeOrd(list *lst, double input);
int getData(list *lst, int input, double *output);