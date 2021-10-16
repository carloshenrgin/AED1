typedef struct list* List;

List initializeList();
int emptyList(List l);
int fullList(List l);
int insertGrade(List l, void *input, int type);
int removeGrade(List l, void *input, int type);
int getGradebyPos(List l, int pos, void **output, int *type);
