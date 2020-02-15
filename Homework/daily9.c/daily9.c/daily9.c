/**********************************************************************
 Program: daily9.c
 Author: Sam Pickell
 Date: April 7, 2016
 Time spent: 2 hours and 33 minutes
 Purpose: The purpose of this program is to use quicksort as we talked
    about in class to sort an already sorted array, an array in reverse
    order, and an array with random values in it.
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void quicksort( int[], int iLeft, int iRight);
int partition( int[], int iLeft, int iRight);
void my_swap(int* a, int* b);


int main(int argc, char* argv[])
{
    int sorted[] = {1, 2, 3, 4, 5};
    int reverse[] = {5, 4, 3, 2, 1};
    int random[] = {rand(), rand(), rand(), rand(), rand()};
    int i;
    
    
    printf("Unsorted 'sorted' array:  ");
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", sorted[i]);
    }
    
    printf("\n");
    
    quicksort(sorted, 0, SIZE - 1);
    
    printf("Sorted 'sorted' array:  ");
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", sorted[i]);
    }
    
    printf("\n\n");
    
    
    
    
    printf("Unsorted 'reverse' array:  ");
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", reverse[i]);
    }
    
    printf("\n");
    
    quicksort(reverse, 0, SIZE - 1);
    
    printf("Sorted 'reverse' array:  ");
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", reverse[i]);
    }
    
    printf("\n\n");
    
    
    
    printf("Unsorted 'random' array:  ");
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", random[i]);
    }
    
    printf("\n");
    
    quicksort(random, 0, SIZE - 1);
    
    printf("Sorted 'reverse' array:  ");
    for(i = 0; i < SIZE; i ++)
    {
        printf("%d ", random[i]);
    }
    
    printf("\n\n");
    
    
    return 0;
    
}



void quicksort(int a[], int iLeft, int iRight)
{
    int j;
    
    if(iLeft < iRight)
    {
        j = partition(a, iLeft, iRight);
        quicksort(a, iLeft, j-1);
        quicksort(a, j+1, iRight);
    }
    
}



int partition(int a[], int iLeft, int iRight)
{
    int pivot, i, j, k = 0;
    
    pivot = a[iLeft];
    i = iLeft; j = iRight + 1;
    
    while(!k)
    {
        do
        {
            i ++;
            
            
        }while(a[i] <= pivot && i <= iRight);
        
        do
        {
            j --;
            
            
        } while(a[j] > pivot);
        
        if(i >= j)
        {
            break;
        }
        
        my_swap(&a[i], &a[j]);
        
    }
    
    my_swap(&a[iLeft], &a[j]);
    
    return j;
}


void my_swap(int* a, int* b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}











