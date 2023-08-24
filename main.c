#include "main.h"

/**
* main - Simple shell main function.
*
* @ac: The argument count.
* @arvs: The argument vector.
* @envp: The environment variables.
*
* Return: Always returns 0.
*/
int main(int ac, char **arvs, char **envp)
{
int status = 0, command_num = 0;
char *input = NULL, *delimiter = " \n", *which = NULL;
size_t num_bytes_allocated = 0;
char **array_tokens;

(void)ac;
(void)envp;

signal(SIGINT, sigint_handler);

while (1)
{
command_num++;
_getline(&input, &num_bytes_allocated, status);
array_tokens = array_maker(input, delimiter);

if (*array_tokens)
{
if (is_builtin(array_tokens))
{
if (builin_handler(array_tokens) == EXIT_CODE)
{
free_main(array_tokens, input);
exit(status);
}
}
else
{
which = _which(array_tokens[0]);
status = which ? _fork(which, array_tokens) :
error_not_found(arvs, array_tokens, command_num);
}
}

free_main(array_tokens, input);
input = NULL;
}

return (0);
}
