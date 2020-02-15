
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[])
{
    QUEUE hQueue;
    int i;
    
    hQueue = queue_init_default();
    if (hQueue == NULL)
    {
        printf("NULL.\n");
        exit(1);
        
    }
    
    for (i = 0; i < 20; i++)
    {
        queue_enqueue(hQueue, i);
        //printf("FRONT: %d\n", queue_front(hQueue, NULL));
    }
    
    while (queue_get_size(hQueue) > 0)
    {
        printf("%d\n", queue_front(hQueue, NULL));
        queue_service(hQueue);
        
        
    }
    
    queue_destroy(&hQueue);
    
    return 0;
}
