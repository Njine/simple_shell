#include "main.h"

/**
* _env_builtin - print environment
*
* @array_of_tokens: command array
*
* Return: 1 for success
*/
int _env_builtin(__attribute__((unused)) char **array_of_tokens)
{
int env_index = 0;

while (__environ[env_index])
{
write(STDOUT_FILENO, __environ[env_index],
strlen(__environ[env_index]));
write(STDOUT_FILENO, "\n", strlen("\n"));
env_index++;
}
return (1);
}
