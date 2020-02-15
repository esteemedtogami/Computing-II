/**********************************************************************
 Program: <name of program>
 Author: <your name>
 Date: <date you finish the program>
 Time spent: 4:56 - 5:45, 7-8:30, 4:19-5:10, 9:00 - 9:50, 10:15- 12:30, 2:15- 4:41, 10:54
 Purpose: The purpose of this program is to blah blah blah
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_queue.h"

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int i, j = 0, k, l, iTest_cases;
    int results[iTest_cases];
    
    //get initial input
    scanf("%d", &iTest_cases);
    clear_keyboard_buffer();
    
    //loop that runs for each test case
    for (i = 0; i < iTest_cases; i++)
        {
    
            int iCar_size, iBoat_size, iNumber_of_cars, iSum = 0, iTrips = 0;
            char cDirection, cLast = '\0';
            QUEUE left_queue = queue_init_default();
            QUEUE right_queue = queue_init_default();
            QUEUE good_left_queue = queue_init_default();
            QUEUE good_right_queue = queue_init_default();
            Status status;
            
            scanf("%d %d", &iBoat_size, &iNumber_of_cars);
            clear_keyboard_buffer();
            
            
            for (k = 1; k <= iNumber_of_cars; k++)
            {
                
                
                scanf("%d %c", &iCar_size, &cDirection);
                clear_keyboard_buffer();
                
                //determine which queue to put the data into
                if (cDirection == 'l' || cDirection == 'L')
                {
                    if (cLast != cDirection && cLast != '\0')
                    {
                        //printf("YOU HAVE ENTERED LEFT\n");
                        
                        for (l = 0; l <= queue_get_size(right_queue); l++)
                        {
                            queue_enqueue(good_right_queue, queue_front(right_queue, &status));
                            queue_service(right_queue);
                            
                            if (queue_empty(right_queue))
                            {
                                //printf("Right queue has been emptied.");
                            }
                            
                            //printf("%d\n", queue_front(good_right_queue, &status));
                        }
                        
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
                        
                        iTrips ++;
                        //printf("%d\n", iTrips);
                        
                    }
                        
                        
                    queue_enqueue(left_queue, iCar_size);
                    //printf("Front left: %d\n", queue_front(left_queue, &status));
                }
                else if (cDirection == 'r' || cDirection == 'R')
                {
                    if (cLast != cDirection && cLast != '\0')
                    {
                        //printf("YOU HAVE ENTERED RIGHT\n");
                        
                        for (l = 0; l <= queue_get_size(left_queue) + 1; l++)
                        {
                            queue_enqueue(good_left_queue, queue_front(left_queue, &status));
                            queue_service(left_queue);
                            
                            if (queue_empty(left_queue))
                            {
                                //printf("Left queue has been emptied.");
                            }
                            //printf("%d\n", queue_front(good_left_queue, &status));
                        }
                        
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
                        iTrips ++;
                        //printf("%d\n", iTrips);
                        
                    }

                    
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
            
                cLast = cDirection;
                iSum = 0;
            }
            
            if (!queue_empty(left_queue))
                {
                   // printf("LEFT NOT EMPTY\n");
                    
                    for (l = 0; l <= queue_get_size(left_queue) + 1; l++)
                    {
                        queue_enqueue(good_left_queue, queue_front(left_queue, &status));
                        queue_service(left_queue);
                        //printf("%d\n", queue_front(good_left_queue, &status));
                    }
                    
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
                    
                    if ((iSum > 0) && (iSum < (iBoat_size * 100)))
                    {
                        iTrips ++;
                        //printf("%d\n", iTrips);
                    }
                    
                    iSum = 0;

                }
                
            if (!queue_empty(right_queue))
                {
                    //printf("RIGHT NOT EMPTY\n");
                    
                    for (l = 0; l <= queue_get_size(right_queue); l++)
                    {
                        queue_enqueue(good_right_queue, queue_front(right_queue, &status));
                        queue_service(right_queue);
                        //printf("%d\n", queue_front(good_right_queue, &status));
                    }
                    
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
                    
                    if ((iSum > 0) && (iSum < (iBoat_size * 100)))
                    {
                        iTrips ++;
                        //printf("%d\n", iTrips);
                    }
                    
                    iSum = 0;
                    
                }
            
        results[j] = iTrips;
        j ++;
        
        //printf("End loop %d\n", j);
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
