typedef struct node* list;

list criaLista();
int listaVazia(list *lst);
int insereOrd(list *lst, char elem);
int removeOrd(list *lst, char elem);
int intercala(list *lst, list *lst2, list *lst3);