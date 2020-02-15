#ifndef QUEUE_H
#define QUEUE_H

#include "status.h"

typedef void* QUEUE;

//init - should have conditions
QUEUE queue_init_default(void);

//enqueue
Status queue_enqueue(QUEUE hQueue, int item);

//service
Status queue_service(QUEUE hQueue); // pop_front

//empty
Boolean queue_empty(QUEUE hQueue);

//front
int queue_front(QUEUE hQueue, Status* pStatus_code);

int queue_get_size(QUEUE hQueue);

//destroy
void queue_destroy(QUEUE* phQueue);


#endif