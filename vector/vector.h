#ifndef VECTOR_H
#define VECTOR_H

typedef int elemType;

struct vector{
    char **address;
    int elemSize;
    int dataMaxSize;
    int dataSize;
};

/*
 * vector initialization/destroy
 */
struct vector vector_init(int elemsize, int maxnum);
void vector_free(struct vector *vec);

/*
 * vector operation
 */
int vector_full(struct vector vec);
int vector_empty(struct vector vec);
int vector_length(struct vector vec);
int vector_size(struct vector vec);
void vector_print(struct vector vec, void *func());

/*
 * vector element operation
 */
void vector_push(struct vector *vec, void *elem);
void vector_pop(struct vector *vec, void *elem);
void vector_insert(struct vector *vec, void *elem, int pos);
void vector_remove(struct vector *vec, void *elem, int pos);

/*
 * vector element search
 */
void* vector_find(struct vector *vec, int pos);

#endif