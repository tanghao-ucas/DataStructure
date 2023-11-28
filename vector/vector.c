#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vector vector_init(int elemsize, int maxnum)
{
    struct vector vec;
    vec.elemSize = elemsize;
    vec.dataMaxSize = maxnum;
    vec.address = (char**)malloc(maxnum * sizeof(char*));
    vec.dataSize = 0;
    return vec;
}

void vector_free(struct vector *vec)
{
    char *p;
    for(int i = 0; i < vec->dataSize; i++){
        p = vec->address[i];
        free(p);
    }
    free(vec->address);
}


int vector_full(struct vector vec)
{
    return (!(vec.dataSize < vec.dataMaxSize));
}

int vector_empty(struct vector vec)
{
    return (!(vec.dataSize > 0));
}

int vector_length(struct vector vec)
{
    return vec.dataSize;
}

int vector_size(struct vector vec)
{
    return vec.dataMaxSize;
}

void vector_print(struct vector vec, void *func())
{
    for(int i = 0; i < vec.dataSize; i++){
        printf("%d ", *(vec.address[i]));
    }
    printf("\n");
}


void vector_push(struct vector *vec, void *elem)
{
    if(vector_full(*vec)){
        printf("Push Error: vector is full\n");
        return;
    }
    char *p = (char*)malloc(vec->elemSize);
    memcpy(p, elem, vec->elemSize);
    vec->address[vec->dataSize++] = p;
}

void vector_pop(struct vector *vec, void *elem)
{
    if(vector_empty(*vec)){
        printf("Pop Error: vector is empty\n");
        return;
    }
    char *p = vec->address[vec->dataSize - 1];
    memcpy(elem, p, vec->elemSize);
    vec->dataSize--;
}

void vector_insert(struct vector *vec, void *elem, int pos)
{
    // Error detection
    if(vector_full(*vec)){
        printf("Insert Error: vector is full\n");
        return;
    }
    if(pos > vec->dataSize + 1){
        printf("Insert Error: invalid insert position\n");
        return;
    }
    // Inserting
    char *p = (char*)malloc(vec->elemSize);
    memcpy(p, elem, vec->elemSize);

    for(int i = vec->dataSize; i > pos - 1; i--){
        vec->address[i] = vec->address[i-1];
    }
    vec->address[pos - 1] = p;
    vec->dataSize++;
}

void vector_remove(struct vector *vec, void *elem, int pos)
{
    // Error detection
    if(vector_empty(*vec)){
        printf("Remove Error: vector is empty\n");
        return;
    }
    if(pos > vec->dataSize){
        printf("Remove Error: invalid remove position\n");
        return;
    }
    // Removing
    char *p = vec->address[pos - 1];
    memcpy(elem, p, vec->elemSize);

    for(int i = pos; i < vec->dataSize; i++){
        vec->address[i-1] = vec->address[i];
    }
    vec->dataSize--;
}

void* vector_find(struct vector *vec, int pos)
{
    if(pos > vec->dataSize){
        return NULL;
    }
    return vec->address[pos-1];
}