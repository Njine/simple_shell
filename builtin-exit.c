#include "main.h"

/**
* _exit_builtin - Handle the built-in exit command.
*
* @array_of_tokens: Command array.
*
* Return: 0 for failure, 1 for success.
*/
int _exit_builtin(char **array_of_tokens)
{
if (array_of_tokens[1] != NULL)
{
int exit_code = atoi(array_of_tokens[1]);
exit(exit_code);
}
else
{
return (EXIT_CODE);
}
}
