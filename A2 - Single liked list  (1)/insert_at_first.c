#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
    /* Creating the new node */
    Slist *new = malloc(sizeof(Slist));

    /* Check whether new node created or not */
    if (new == NULL)
    {
        return FAILURE;
    }

    /* Fill the parts of the node */
    new->data = data;
    new->link = NULL;

    /* If list is empty */
    if (*head == NULL)
    {
        /*If *head is empty then create the first node and assign newnode to it*/
        *head = new; // newnode address will be stored in head
        return SUCCESS;
    }
    else
    {
        /* *head is not empty then store value i.e link in the temp variable */
        Slist *temp = *head; // temp now holds the address of the first node in the linked list.

        /* Storing that new link in the head inserting the element at first */
        *head = new;

        /*the code is setting the link (or next) pointer of the new node to point to
        the node that was originally the first node in the list (temp)*/
        new->link = temp;
    }

    return SUCCESS;
}