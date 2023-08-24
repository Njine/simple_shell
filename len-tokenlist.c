#include "lists.h"

/**
* listtoken_len - Returns the number of elements in a linked list.
*
* @head: A pointer to the first node of the list.
*
* Return: The number of elements in the list.
*/
size_t listtoken_len(const listtoken_t *head)
{
size_t count = 0;
const listtoken_t *current = head;

while (current != NULL)
{
count++;
current = current->next;
}

return (count);
}
