/**********************************************************************
 Program: daily6.c
 Author: Sam Pickell
 Date: 2/19/16
 Time spent: 1 hour 45 minutes
 Purpose: Reverse the order of a linked list in a single function.
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

Node* reverse_linked_list(Node* head);


int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;
    
    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    
    head = reverse_linked_list(head);//call your function to reverse the list (should work for any list given the head node).
    
    
    //print the reversed list.
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
    return 0;
}

Node* reverse_linked_list(Node* head)
{
    Node* temp1 = NULL;
    Node* temp2 = 0;
    
    while (head != 0)
    {
        temp1 = head->next;
        head->next = temp2;
        temp2 = head;
        head = temp1;
    }
    
    return temp2;
}
    
    
