#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == g_data)
        {
            Slist *newnode = (Slist *)malloc(sizeof(Slist));
            if (newnode == NULL)
            {
                printf("Memory allocation failed.\n");
                return FAILURE;
            }
            newnode->data = ndata;
            newnode->link = temp->link; // temp should point newnode
            temp->link = newnode;

            return SUCCESS;
        }
        temp = temp->link; // break the link b/w temp node and the node next to it which newnode also pointing
    }
    return DATA_NOT_FOUND;
}