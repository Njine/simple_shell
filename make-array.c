#include "main.h"

/**
* number_of_tokens - Count the number of tokens in a string.
*
* @input: Input string.
* @delimiter: Delimiter string.
*
* Return: Number of tokens or -1 if failure.
*/
size_t number_of_tokens(char *input, char *delimiter)
{
char *token;
size_t count_token = 0;

count_token = 0;
token = strtok(input, delimiter);
while (token != NULL)
{
count_token++;
token = strtok(NULL, delimiter);
}
return (count_token);
}

/**
* array_maker - Create a NULL-terminated array of tokens from a string.
*
* @input: Input string.
* @delimiter: Delimiter string.
*
* Return: Returns NULL on failure and the array on success.
*/
char **array_maker(char *input, char *delimiter)
{
char *token, *input_cpy;
char **tokar;
size_t count_token, indexto;

tokar = NULL;
input_cpy = strdup(input);
if (input_cpy == NULL)
{
perror("array_maker() Error: input_cpy malloc failure");
return (NULL);
}

count_token = number_of_tokens(input_cpy, delimiter);
tokar = (char **)malloc(sizeof(char *) * (count_token + 1));
if (tokar == NULL)
{
perror("array_maker() Error: tokar malloc failure");
free(input_cpy);
return (NULL);
}

token = strtok(input_cpy, delimiter);
for (indexto = 0; indexto < count_token; indexto++)
{
tokar[indexto] = strdup(token);
if (tokar[indexto] == NULL)
{
while (indexto > 0)
free(tokar[--indexto]);
free(tokar);
perror("array_maker() Error: tokar malloc failure");
return (NULL);
}
token = strtok(NULL, delimiter);
}
free(input_cpy);
tokar[count_token] = NULL;
return (tokar);
}

