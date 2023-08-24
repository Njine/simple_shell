#include "lists.h"
#include <stdio.h>

/**
* print_listtoken - prints all  elements of listtoken_t list
* @head: points to  1st node
*
* Return: the no of nodes
*/
size_t print_listtoken(const listtoken_t *head)
{
int number = 0;
const listtoken_t *now;

if (head == NULL)
return (0);

for (now = head; now != NULL; now = now->next)
{
printf("%s\n", now->token);
number++;
}

return (number);
}
