#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_queue.h"

struct node
{
    int data;
    Node* next;
    Node* prev;
};


struct queue
{
    int front;
    int back;
    int size;
    
    Node* head;
    Node* tail;
};

typedef struct queue Queue;

QUEUE queue_init_default(void)
{
    Queue* pQueue = NULL;
    
    pQueue = (Queue*) malloc(sizeof(Queue));
    if (pQueue != NULL)
    {
        pQueue->front = -1;
        pQueue->back = 0;
        pQueue->size = 0;
        pQueue->head = NULL;
        pQueue->tail = NULL;
    }
    
    return pQueue;
}


Status queue_enqueue(QUEUE hQueue, int item)
{
    Queue* pQueue = (Queue*) hQueue;
    Node* temp;
    
    
    
    if (pQueue->front == -1)
    {
        pQueue->front = 0;
    }
    
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        return FAILURE;
    }
    temp->data = item;
    temp->prev = pQueue->tail;
    temp->next = pQueue->head;
    
    pQueue->tail = pQueue->head;
    pQueue->head = temp;
    
    pQueue->size++;
    
    return SUCCESS;
}

Status queue_service(QUEUE hQueue)
{
    Queue* pQueue = (Queue*) hQueue;
    Node* temp;
    
    if(pQueue->head == NULL)
    {
        return FAILURE;
    }
    
    
    temp = pQueue->head;
    
    pQueue->head = pQueue->head->next;
    free(temp);
    pQueue->size --;
    return SUCCESS;
}

Boolean queue_empty(QUEUE hQueue)
{
    Queue* pQueue = (Queue*) hQueue;
    
    //pQueue->size = 0;
    
    return (Boolean)(pQueue->head == NULL);
}

int queue_front(QUEUE hQueue, Status* pStatus_code)
{
    Queue* pQueue = (Queue*) hQueue;
    
    if (pQueue->head == NULL)
    {
        if (pStatus_code != NULL)
        {
            *pStatus_code = FAILURE;
        }
        
        return -9001;
    }
    
    if (pStatus_code != NULL)
    {
        *pStatus_code = SUCCESS;
    }
    
    return pQueue->head->data;
}

int queue_get_size(QUEUE hQueue)
{
    Queue* pQueue = (Queue*) hQueue;
    
    return pQueue->size;
    
}

void queue_destroy(QUEUE* phQueue)
{
    Queue* pQueue = (Queue*) *phQueue;
    Node* temp;
    
    temp = pQueue->head;
    while (temp != NULL)
    {
        pQueue->head = pQueue->head->next;
        free(temp);
        temp = pQueue->head;
    }
    
    free(pQueue);
    *phQueue = NULL;
    
    return;
}


