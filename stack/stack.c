#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack stack_init(int elemsize, int maxnum)
{
    struct stack st;
    st.elemSize = elemsize;
    st.dataMaxNum = maxnum;
    st.allocSize = elemsize * maxnum;
    st.data = (char*)malloc(st.allocSize);
    st.dataNum = 0;
    return st;
}

void stack_config(struct stack st)
{
    printf("elemSize: %d\ndataMaxNum: %d\ndataNum: %d\n", st.elemSize, st.dataMaxNum, st.dataNum);
}

void stack_print(struct stack st)
{
    if(!(st.dataNum > 0)){
        printf("Print Warning: The stack is empty\n");
        return;
    }
    char *p = st.data;
    for(int i = 0; i < st.dataNum; i++){
        p = st.data + st.elemSize * i;
        printf("%d ", *(elemType*)p);
    }
    printf("\n");
}

void stack_push(struct stack *st, void *elem)
{
    if(!(st->dataNum < st->dataMaxNum)){
        printf("Push Error: stack is full\n");
        return;
    }
    char *p = st->data;
    p = p + st->dataNum * st->elemSize;
    memcpy(p, elem, st->elemSize);
    st->dataNum++;
}

void stack_pop(struct stack *st, void *elem)
{
    if(!(st->dataNum > 0)){
        printf("Pop Error: stack is empty\n");
        return;
    }
    char *p = st->data + st->elemSize * (st->dataNum - 1);
    memcpy(elem, p, st->elemSize);
    st->dataNum--;
}