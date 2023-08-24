#include "main.h"


/**
* _getenv - Get the value of an environment variable.
*
* This function searches for the specified environment variable by name
* and returns its value.
*
* @name: The name of the environment variable to retrieve.
*
* Return: The value of the environment variable or NULL if not found.
*/
char *_getenv(const char *name)
{
size_t namelen = strlen(name);
unsigned int env_index;
if (name == NULL || __environ == NULL)
return (NULL);




for (env_index = 0; __environ[env_index] != NULL; env_index++)
{
if (strncmp(__environ[env_index], name, namelen) == 0 &&
__environ[env_index][namelen] == '=')
{
size_t value_length = strlen(__environ[env_index]) - namelen - 1;

char *env_var = (char *)malloc((value_length + 1) * sizeof(char));
if (env_var == NULL)
{
perror("_getenv() Error: env_var malloc failed");
return (NULL);
}

strcpy(env_var, __environ[env_index] + namelen + 1);

return (env_var);
}
}

return (NULL);
}
