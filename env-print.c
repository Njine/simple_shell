#include "main.h"

/**
* _print_env - Print all environment variables.
*
* This function iterates through the `__environ` array and prints each
* environment variable to stdout.
*
* Return: Always returns 0.
*/
int _print_env(void)
{
unsigned int environ_index;

if (__environ == NULL)
{
return (1);
}

for (environ_index = 0; __environ[environ_index] != NULL; environ_index++)
{
printf("%s\n", __environ[environ_index]);
}

return (0);
}

