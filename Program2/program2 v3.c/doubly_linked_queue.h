#ifndef DOUBLY_LINKED_QUEUE_H
#define DOUBLY_LINKED_QUEUE_H

#include "status.h"

struct node;
typedef struct node Node;

typedef void* QUEUE;


QUEUE queue_init_default(void);


Status queue_enqueue(QUEUE hQueue, int item);


Status queue_service(QUEUE hQueue);


Boolean queue_empty(QUEUE hQueue);


int queue_front(QUEUE hQueue, Status* pStatus_code);

int queue_get_size(QUEUE hQueue);


void queue_destroy(QUEUE* phQueue);


#endif
