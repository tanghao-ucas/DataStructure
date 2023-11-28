#ifndef STACK_H
#define STACK_H

typedef int elemType;

struct stack
{
    char *data; // data 
    int elemSize;   // element size
    int allocSize;  // allocated buffer size
    int dataNum;    // data number
    int dataMaxNum; // data max number
};

struct stack stack_init(int elemsize, int maxnum);
void stack_config(struct stack st);

void address_search(void *p);
void stack_print(struct stack st);

void stack_push(struct stack *st, void *elem);
void stack_pop(struct stack *st, void *elem);

#endif