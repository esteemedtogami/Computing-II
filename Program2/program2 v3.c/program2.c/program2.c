/**********************************************************************
 Program: Ferry Queue
 Author: Sam Pickell
 Date: 3/4/16
 Resubmit date: 3/29/16
 Time spent: 13 hours
 Purpose: The purpose of this program is to use two queues to process data
    and keep track of the number of times a ferry picks up a number of cars
    and transports them across a river.
 Reason for Resubmit: Last post didn't produce the correct answer and was
    messy. The correct solutions can be found now and the code is cleaner.
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_queue.h"

#define SIZE 100

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    Status status;
    QUEUE left_queue, right_queue;
    
    int trips, trials, j, test_cases, car, load, s;
    int array_results[SIZE];
    
    int check;
    
    scanf("%d", &test_cases);
    clear_keyboard_buffer();
    
    for (int i = 0; i < test_cases; i++)
    {
        char bank;
        int service_left = 0, service_right = 0, capacity;
        left_queue = queue_init_default();
        right_queue = queue_init_default();
        scanf("%d %d", &capacity, &trials);
        clear_keyboard_buffer();
        
        load = 0;
        check = 1;
        
        for (j = 0; j < trials; j++)
        {
            scanf("%d %c", &car, &bank);
            clear_keyboard_buffer();
            
            if (bank == 'l')
            {
                service_left ++;
                queue_enqueue(left_queue, car);
            }
            else
            {
                service_right ++;
                queue_enqueue(right_queue, car);
            }
        }
        
        trips = 0;
        capacity *= 100;
        
        while (!queue_empty(left_queue) || !queue_empty(right_queue))
        {
            
            load = 0;
            if (check)
            {
                while (!queue_empty(left_queue) && load + queue_front(left_queue, &status) <= capacity)
                {
                    load += queue_front(left_queue, &status);
                    queue_service(left_queue);
                }
            }
            
            else
            {
                while (!queue_empty(right_queue) && load + queue_front(right_queue, &status) <= capacity)
                {
                    load += queue_front(right_queue, &status);
                    queue_service(right_queue);
                }
            }
            
            ++trips;
            check = 1 - check;
        }
        
        array_results[i] = trips;
    }
    
    for (s = 0; s < test_cases; s++)
    {
        printf("%d\n", array_results[s]);
    }
    
    return 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    
    do
    {
        scanf("%c", &c);
    } while (c != '\n');
    
}
