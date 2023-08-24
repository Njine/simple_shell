#include "main.h"

/**
* _unsetenv - Remove an environment variable by name.
*
* @name: The name of the environment variable to remove.
*
* Return: 0 on success, -1 on failure.
*/
int _unsetenv(const char *name)
{
unsigned int env_index;
int found_index = -1;
unsigned int i;
if (name == NULL || __environ == NULL)
return (-1);



/* Find the index of the environment variable to remove. */
for (env_index = 0; __environ[env_index]; env_index++)
{
if (strncmp(__environ[env_index], name, strlen(name)) == 0)
{
found_index = env_index;
break;
}
}
/* If not found, return success (0) since it's not an error. */
if (found_index == -1)
return (0);

/* Free the memory occupied by the environment variable. */
free(__environ[found_index]);

/* Shift the remaining environment variables to fill the gap. */

for (i = found_index; __environ[i]; i++)
{
__environ[i] = __environ[i + 1];
}

return (0);
}
