typedef struct aluno dados;
typedef struct node* list;

struct aluno{
    int faltas;
    float media;
    unsigned int matricula;
    char nome[21];
};

list criaLista();
int listaVazia(list *lst);
int insereElem(list *lst, dados leitura);
int removeElem(list *lst, dados leitura);
int tamanhoLista(list *lst);
int getPos(list *lst, int pos);
int limpaLista(list *lst);