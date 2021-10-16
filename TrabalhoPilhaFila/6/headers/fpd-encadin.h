typedef struct node* pQueue;

pQueue initQueue();
int emptyQueue(pQueue q);
int insertSort(pQueue *q, int age, int severity, char *name, char *organ);
int removeBeg(pQueue *q, int *severity, int *age, char **name, char **organ);
int back2Empty(pQueue *q);
int peek(pQueue q, int *severity, int *age, char **name, char **organ);