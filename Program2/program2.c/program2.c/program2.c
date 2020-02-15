/**********************************************************************
 Program: <name of program>
 Author: <your name>
 Date: <date you finish the program>
 Time spent: 4:56 - 5:45, 7-8:30, 4:19-5:10, 9:00 - 9:50, 10:15- 12:30, 2:15-
 Purpose: The purpose of this program is to blah blah blah
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_queue.h"

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int i, j = 0, k, iTest_cases;
    int results[iTest_cases];
    
    //get initial input
    scanf("%d", &iTest_cases);
    clear_keyboard_buffer();
    
    //loop that runs for each test case
    for (i = 0; i < iTest_cases; i++)
        {
    
            int iCar_size, iBoat_size, iNumber_of_cars;
            char cDirection;
            QUEUE left_queue = queue_init_default();
            QUEUE right_queue = queue_init_default();
            QUEUE good_left_queue = queue_init_default();
            QUEUE good_right_queue = queue_init_default();
            Status status;
            
            scanf("%d %d", &iBoat_size, &iNumber_of_cars);
            clear_keyboard_buffer();
            
            for (k = 0; k < iNumber_of_cars; k++)
            {
                scanf("%d %c", &iCar_size, &cDirection);
                clear_keyboard_buffer();
                
                //determine which queue to put the data into
                if (cDirection == 'l' || cDirection == 'L')
                {
                    queue_enqueue(left_queue, iCar_size);
                    //printf("Front left: %d\n", queue_front(left_queue, &status));
                }
                else if (cDirection == 'r' || cDirection == 'R')
                {
                    queue_enqueue(right_queue, iCar_size);
                    //printf("Front right: %d\n", queue_front(right_queue, &status));
                }
                else
                {
                    printf("Failed to enter \"left\" or \"right\".\n");
                    queue_destroy(&left_queue);
                    queue_destroy(&right_queue);
                    exit(1);
                }
            }
            
            
            //fill the good queues
            
            for (k = 0; k <= queue_get_size(left_queue) + 1; k++)
            {
                queue_enqueue(good_left_queue, queue_front(left_queue, &status));
                queue_service(left_queue);
                printf("%d\n", queue_front(good_left_queue, &status));
            }
            
            for (k = 0; k <= queue_get_size(right_queue); k++)
            {
                queue_enqueue(good_right_queue, queue_front(right_queue, &status));
                queue_service(right_queue);
                printf("%d\n", queue_front(good_right_queue, &status));
            }
            
                //process data
                //This will look at the front and compare it to the
                //boat's capacity. If there is enough space the car,
                //let it on to the boat. If not, it needs to wait for another
                //trip. Make sure to keep track of the number of trips.
                int iTrips = 0, iSum = 0;
                    
                for (;;)
                {
                    while (((queue_front(good_left_queue, &status) + iSum) <= (iBoat_size * 100))
                            && !queue_empty(good_left_queue))
                    {
                        if ((queue_front(good_left_queue, &status) + iSum) > (iBoat_size * 100))
                        {
                            break;
                        }
                            
                        iSum += queue_front(good_left_queue, &status);
                        queue_service(good_left_queue);
                        //printf("Current sum: %d\n", iSum);
                        //printf("Front left: %d\n", queue_front(left_queue, &status));
                            
                    }
                        
                    if (queue_empty(good_left_queue) && queue_empty(good_right_queue))
                    {
                        break;
                    }
                    
                    iTrips ++;
                    iSum = 0;
                        
                    while (((queue_front(good_right_queue, &status) + iSum) <= (iBoat_size * 100))
                            && !queue_empty(good_right_queue))
                    {
                        if ((queue_front(good_right_queue, &status) + iSum) > (iBoat_size * 100))
                        {
                            break;
                        }
                        
                        iSum += queue_front(good_right_queue, &status);
                        queue_service(good_right_queue);
                        //printf("Current sum: %d\n", iSum);
                        //printf("Front right: %d\n", queue_front(right_queue, &status));
                        
                    }
                    
                    if (queue_empty(good_left_queue) && queue_empty(good_right_queue))
                    {
                        break;
                    }
                    
                    iTrips ++;
                    iSum = 0;
                    
                    if (queue_empty(good_left_queue) && queue_empty(good_right_queue))
                    {
                        break;
                    }
                    
                }
            
            
            
                results[j] = iTrips;
                j ++;
        
        printf("End loop %d\n", j);
        queue_destroy(&left_queue);
        queue_destroy(&right_queue);
        queue_destroy(&good_left_queue);
        queue_destroy(&good_right_queue);
            
    }
    
    for (i = 0; i < iTest_cases; i++)
    {
        printf("%d\n", results[i]);
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