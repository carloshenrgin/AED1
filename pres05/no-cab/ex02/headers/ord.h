typedef struct node* list;

list criaLista();
int listaVazia(list lst);
int insereElem(list lst, int elem);
int removeElem(list lst, int elem);
int getElem(list lst, int pos, int *output);
void limpaLista(list lst);