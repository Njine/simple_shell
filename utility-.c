#include "main.h"

/**
* malloc_char - allocates memory for a string and returns a pointer to it
*
* @string: pointer to the string variable
* @size_of_malloc: size of memory to allocate
* @error_message: error message to print on failure
*
* Return: pointer to the allocated memory, or NULL on failure
*/
char *malloc_char(char **string, size_t size_of_malloc, char *error_message)
{
*string = (char *)malloc(size_of_malloc * sizeof(char));
if (*string == NULL)
{
perror(error_message);
return (NULL);
}
return (*string);
}

/**
* malloc_array - allocates memory for array of strngs & returns pointer
*
* @array: pointer to the array of strings
* @size_of_malloc: size of memory to allocate
* @error_message: error message to print on failure
*
* Return: pointer to the allocated memory, or NULL on failure
*/
char **malloc_array(char **array, size_t size_of_malloc, char *error_message)
{
array = (char **)malloc(size_of_malloc * sizeof(char *));
if (array == NULL)
{
perror(error_message);
return (NULL);
}
return (array);
}

/**
* copy_array - copies an array of strings from source to destination
*
* @destination: destination array
* @source: source array
*
* Return: 0 on success, -1 on failure
*/
int copy_array(char **destination, char **source)
{
size_t new_env_index;

for (new_env_index = 0; source[new_env_index]; new_env_index++)
{
destination[new_env_index] = strdup(source[new_env_index]);
if (destination[new_env_index] == NULL)
{
perror("_setenv() Error: strdup failed");
return (-1);
}
}
return (0);
}

/**
* _env_name_exists - check if variable with given name exists in env
*
* @name: name string to check
*
* Return: index of the variable if found, -1 otherwise
*/
int _env_name_exists(const char *name)
{
int env_index;

for (env_index = 0; __environ[env_index]; env_index++)
{
if (strncmp(__environ[env_index], name, strlen(name)) == 0)
{
return (env_index);
}
}
return (-1);
}

/**
* _env_length - calculates the number of environment variables
*
* Return: number of environment variables
*/
int _env_length(void)
{
unsigned int env_length;

for (env_length = 0; __environ[env_length]; env_length++)
{
;
}
return (env_length);
}
