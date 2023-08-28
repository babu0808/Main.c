#include "sll.h"
int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    if (*head == NULL)
    {
        // List is empty, insertion not possible
        // free(newnode);
        return LIST_EMPTY;
    }

    // case 1 -> Insert before the head node where the data found at first node
    if ((*head)->data == g_data)
    {
        Slist *newnode = (Slist *)malloc(sizeof(Slist));
        if (newnode == NULL)
        {
            printf("Memory not allocated\n");
            return FAILURE;
        }
        newnode->data = ndata;
        newnode->link = *head; // The new node's next should point to the current head
        *head = newnode;       // Update the head to point to the new node
        return SUCCESS;
    }

    // case 1 -> Insert before a node that is not the head
    Slist *temp = *head;
    while (temp->link != NULL)
    {
        if (temp->link->data == g_data)
        {
            Slist *newnode = (Slist *)malloc(sizeof(Slist));
            if (newnode == NULL)
            {
                printf("Memory not allocated\n");
                return FAILURE;
            }
            newnode->data = ndata;
            newnode->link = temp->link; // The new node's next should point to the node after temp
            temp->link = newnode;       // Update temp's next to point to the new node
            return SUCCESS;
        }
        temp = temp->link;
    }

    // case 3 -> Data not found in the list
    return DATA_NOT_FOUND;
}
