typedef struct node* list;

list initList();
int emptyList(list l);
int evenNode(list listed, list comp);
int insertNode(list *l, char *name, int *organFlags, char **recNames);
int removeNode(list *l, char *name, int *organFlags, char **recNames);
int getDatabyPos(list l, int pos, char **name, char ***recNames, int **organFlag);
int removeFst(list *l, char **name, char ***recNames, int **organFlag);
