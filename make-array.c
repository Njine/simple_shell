#include "main.h"

/**
 * number_of_tokens - function  returns  no of tokens in a string
 *
 * Description: function  returns no of tokens in string
 *
 * @input:  string input
 * @delimiter:  string delimiter
 *
 * Return: -1 if failure and a number if successful
 */
size_t number_of_tokens(char *input, char *delimiter)
{
    char *symb = strtok(input, delimiter);
    size_t symb_num = 0;

    for (; symb != NULL; symb = strtok(NULL, delimiter))
    {
        symb_num++;
    }

    return (symb_num);
}
/**
 * array_maker - function creates a NULL terminated array of a string delimited
 *
 * Description: function creates a NULL terminated array of a string delimited
 *
 * @input: input string
 * @delimiter: delimiter string
 *
 * Return: returns NULL on failure and the array on success
 */
char **array_maker(char *input, char *delimiter)
{
	char *cpy_load, *symb;
	char **symb_array;
	size_t symb_num, index_symb, free_symb;

	symb_array = NULL;
	malloc_char(&cpy_load, strlen(input) + 1,
			"array_maker() Error: cpy_load maoloc failure");
	strcpy(cpy_load, input);
	symb_num = number_of_tokens(cpy_load, delimiter);
	symb_array = malloc_array(symb_array, symb_num + 1,
			"array_maker() Error: symb_array** maoloc failure");
	strcpy(cpy_load, input);
	symb = strtok(cpy_load, delimiter);
	for (index_symb = 0; index_symb < symb_num; index_symb++)
	{
		symb_array[index_symb] = (char *) malloc(sizeof(char) *
				strlen(symb) + 1);
		if (symb_array[index_symb] == NULL)
		{
			for (free_symb = 0;
					free_symb < index_symb;
					free_symb++)
				free(symb_array[free_symb]);
			free(cpy_load);
			free(symb_array);
			perror("array_maker() Error: symb_array maoloc failure");
			return (NULL);
		}
		strcpy(symb_array[index_symb], symb);
		symb = strtok(NULL, delimiter);
	}
	free(cpy_load);
	symb_array[symb_num] = NULL;
	return (symb_array);
}