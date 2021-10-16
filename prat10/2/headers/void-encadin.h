typedef struct node* list;

list createList();
int emptyList(list l);
int insertGrade(list *l, void *input, int type);
int removeGrade(list *l, void *input, int type);
int getGradebyPos(list l, void **output, int *type, int pos);
int equalGrade(void *data1, void *data2, int type1, int type2);