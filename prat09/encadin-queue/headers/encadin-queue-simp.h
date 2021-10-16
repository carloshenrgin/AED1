typedef struct queue* Queue;

Queue newQ();
int emptyQ(Queue q);
int insertEnd(Queue q, char *name, int vol, float price);
int removeStart(Queue q, char **name, int *vol, float *price);
int backToEmpty(Queue q);
int eraseQ(Queue *q);