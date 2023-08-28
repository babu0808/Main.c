#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    if (*head == NULL)
    {
        if (n == 1)
        {
            insert_at_first(head, data);
            return SUCCESS;
        }
        return LIST_EMPTY;
    }

    if (n == 1)
    {
        insert_at_first(head, data);
        return SUCCESS;
    }

    if (n <= 0)
    {
        return POSITION_NOT_FOUND;
    }

    Slist *temp = *head;
    n = n - 2;
    while (n-- > 0)
    {
        temp = temp->link;
        if (temp == NULL)
            return POSITION_NOT_FOUND;
    }

    Slist *new_node = malloc(sizeof(Slist));
    if (new_node == NULL)
    {
        return FAILURE; // Handle memory allocation failure
    }

    new_node->data = data;
    new_node->link = temp->link;
    temp->link = new_node;

    return SUCCESS;
}
