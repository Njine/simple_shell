#include "main.h"

/**
* free_main - Free memory allocated for the main function.
*
* This function deallocates memory used by the tokenized string
* and the input string in the main function.
*
* @array_of_tokens: Tokenized string to be freed.
* @input: Input string to be freed.
*/
void free_main(char **array_of_tokens, char *input)
{
int index;

for (index = 0; array_of_tokens[index]; index++)
free(array_of_tokens[index]);
free(array_of_tokens);
free(input);
}

/**
* free_which - Free memory allocated in the 'which' function.
*
* This function deallocates memory used by the 'which' function,
* including the path_var and array_of_tokens.
*
* @path_var: Path variable to be freed.
* @array_of_tokens: Tokenized string to be freed.
*/
void free_which(char **path_var, char **array_of_tokens)
{
int index;

if (array_of_tokens != NULL)
{
for (index = 0; array_of_tokens[index]; index++)
if (array_of_tokens[index] != NULL)
free(array_of_tokens[index]);
free(array_of_tokens);
}
if (*path_var != NULL)
free(*path_var);
}
