#include "lists.h"

/**
* add_nodetoken_end - adds a new node at the end of a listtoken_t list
*
* Description: function adds a new node to the end of the linked list
*
* @head: points to a pointer that points to the first node
* @token: the token to add
*
* Return: the address of the new element, or NULL if it failed
*/
listtoken_t *add_nodetoken_end(listtoken_t **head, char *token)
{
listtoken_t *new_branch, *last_branch;

if (head == NULL)
return (NULL);

new_branch = malloc(sizeof(listtoken_t));
if (new_branch == NULL)
return (NULL);

new_branch->token = token;
new_branch->token_length = strlen(token);
new_branch->next = NULL;

if (*head == NULL)
{
*head = new_branch;
}
else
{
last_branch = *head;
do {
last_branch = last_branch->next;
} while (last_branch->next != NULL);

last_branch->next = new_branch;
}

return (new_branch);
}
