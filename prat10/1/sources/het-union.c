#include <stdlib.h>
#include "..\headers\het-union.h"

#define MAX 30

struct list{
    int type[MAX];
    union{
        float numGrade;
        char conGrade;
    }data[MAX];
    int end;
};

List initializeList(){
    List l = (List) malloc(sizeof(struct list));
    if(l != NULL)
        l->end = 0;

    return l;
}

int emptyList(List l){
    if(l->end == 0)
        return 1;
    return 0;
}

int fullList(List l){
    if(l->end == MAX)
        return 1;
    return 0;
}

int insertGrade(List l, void *input, int type){
    if(l == NULL || fullList(l) == 1)
        return 0;

    if(type == 1){
        l->data[l->end].conGrade = *(char *) input;
        l->type[l->end] = type;
    }

    else{
        l->data[l->end].numGrade = *(float *) input;
        l->type[l->end] = type;
    }

    l->end++;
    return 1;
}

int removeGrade(List l, void *input, int type){
    if(l == NULL || emptyList(l) == 1)
        return 0;

    int i;
    for(i = 0; i < l->end; i++){
        if(l->type[i] == type){
            if(type == 1 && l->data[i].conGrade == *(char *) input)
                break;
            else if(l->data[i].numGrade == *(float *) input)
                break;
        }
    }


    if(i == l->end)
        return 0;

    int j;
    for(j = i; j < l->end - 1; j++){
        if(l->type[j + 1] == 1){
            l->data[j].conGrade = l->data[j + 1].conGrade;
        }
        else{
            l->data[j].numGrade = l->data[j + 1].numGrade;
        }
        l->type[j] = l->type[j + 1];
    }

    l->end--;
    return 1;
}

int getGradebyPos(List l, int pos, void **output, int *type){
    if(emptyList(l) == 1 || pos > l->end)
        return 0;

    if(l->type[pos - 1] == 1)
        *output = &(l->data[pos - 1].conGrade);

    else
        *output = &(l->data[pos - 1].numGrade);

    *type = l->type[pos - 1];

    return 1;
}