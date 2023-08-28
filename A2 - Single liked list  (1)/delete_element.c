#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    // Case 1: List is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }
    else
    {
        // Case 2: List is not empty
        Slist *temp = *head;
        Slist *prev = NULL;

        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                {
                    *head = temp->link; // Update head to point to the next node (delete first node)
                }
                else
                {
                    prev->link = temp->link; // Update previous node's link to skip the current node
                }
                free(temp); // Deallocate memory of the node to be deleted
                return SUCCESS;
            }
            // return SUCCESS;
            prev = temp;       // Move prev to current position
            temp = temp->link; // Move temp to the next node
        }

        return DATA_NOT_FOUND; // Data not found in the list
    }
}
