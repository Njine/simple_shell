#include "main.h"

/**
* error_not_found - Prints custom error for command not found
* @arvs: command-line args
* @array_of_tokens:  array of strings that have been tokenized
* @command_num: numbercounter
*
* Return: void
*/
int error_not_found(char **arvs, char **array_of_tokens, size_t command_num)
{
char *str_er;
char *num_cmd_str = _itoa(command_num);
int size = (strlen(arvs[0]) + (2 * strlen(": ")) +
digit_counter(command_num) + strlen(array_of_tokens[0]) +
strlen(": not found\n") + 1);

malloc_char(&str_er, size, "error_not_found Error: malloc error");
strcpy(str_er, arvs[0]);
strcat(str_er, ": ");
strcat(str_er, num_cmd_str);
strcat(str_er, ": ");
strcat(str_er, array_of_tokens[0]);
strcat(str_er, ": not found\n");
strcat(str_er, "\0");

write(STDERR_FILENO, str_er, strlen(str_er));
free(str_er);
free(num_cmd_str);
return (127);
}
