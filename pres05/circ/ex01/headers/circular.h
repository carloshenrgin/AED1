typedef struct node* list;

list criaLista();
int listaVazia(list *lst);
int insereFinal(list *lst, int input);
int removeInicio(list *lst, int *output);
int obtemValor(list *lst, int pos, int *output);
