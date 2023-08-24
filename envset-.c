#include "main.h"

/**
* create_env_var - Create a new environment variable string.
*
* @name: Name of the environment variable.
* @value: Value of the environment variable.
*
* Return: Pointer to the newly created environment variable string.
*/
static char *create_env_var(const char *name, const char *value)
{
char *env_var;
size_t env_var_length = strlen(name) + strlen(value) + 2;

env_var = (char *)malloc(env_var_length);

if (env_var == NULL)
{
perror("_setenv() Error: env_var malloc failed");
return (NULL);
}

snprintf(env_var, env_var_length, "%s=%s", name, value);
return (env_var);
}

/**
* find_env_index - Find the index of an environment variable by name.
*
* @name: Name of the environment variable to find.
*
* Return: Index of env variable in __environ array or -1 if not found
*/
static int find_env_index(const char *name)
{
int env_index;

if (name == NULL || __environ == NULL)
return (-1);

for (env_index = 0; __environ[env_index] != NULL; env_index++)
{
if (strncmp(__environ[env_index], name, strlen(name)) == 0 &&
__environ[env_index][strlen(name)] == '=')
{
return (env_index);
}
}

return (-1);
}

/**
* _setenv - Set or update an environment variable.
*
* @name: Name of the environment variable.
* @value: Value of the environment variable.
* @overwrite: Whether to overwrite the variable if it already exists.
*
* Return: 0 on success, -1 on failure.
*/
int _setenv(const char *name, const char *value, int overwrite)
{
int env_index = find_env_index(name);
char *new_env_var = create_env_var(name, value);

if (!name || !value || env_index == -1 || overwrite)
{
free(__environ[env_index]);
__environ[env_index] = new_env_var;
}
else
{
int env_count = 0;
char **new_environ = NULL;
int i;

while (__environ[env_count])
env_count++;

new_environ = malloc((env_count + 2) * sizeof(char *));
if (!new_environ)
{
perror("_setenv() Error: malloc failed");
free(new_env_var);
return (-1);
}

for (i = 0; i < env_count; i++)
new_environ[i] = __environ[i];

new_environ[env_count] = new_env_var;
new_environ[env_count + 1] = NULL;
free(__environ);
__environ = new_environ;
}

return (0);
}
