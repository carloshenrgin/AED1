typedef struct queue* Queue;

Queue newQ();
int emptyQ(Queue q);
int fullQ(Queue q);
int insertEnd(Queue q, char *input);
int removeStart(Queue q, char **output);

