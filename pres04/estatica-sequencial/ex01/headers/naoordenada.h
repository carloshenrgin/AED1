typedef struct lista* list;

list criaLista();
int listaVazia(list lst);
int listaCheia(list lst);
int insereElem(list lst, float elem);
int removeElem(list lst, float elem);
void limpaLista(list lst);
void getPos(list lst, int pos);
void imprimeLista(list lst);