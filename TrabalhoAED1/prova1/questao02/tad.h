typedef struct node* list;


struct bebida{
    char bebida[10];
    int vol;
    float preco;
};


list criaLista();
int listaVazia(list lst);
int listaCheia(list lst);
int igual(struct bebida novo, struct bebida atual);
int maior(struct bebida novo, struct bebida atual);
int menor(struct bebida novo, struct bebida atual);
int insereBebida(list lst, struct bebida data);
int removeBebida(list lst, struct bebida data);
