typedef struct node* list;

list criaLista();
int listaVazia(list *lst);
int insereInicio(list *lst, int input);
int removeFinal(list *lst, int *output);
int obtemValor(list *lst, int pos, int *output);
