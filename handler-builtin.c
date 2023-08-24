#include "main.h"

/**
* is_builtin - Check if a command is a built-in.
*
* @array_of_tokens: The command array.
*
* Return: 1 if it's a built-in, 0 if not.
*/
int is_builtin(char **array_of_tokens)
{
int builtin;
const struct builtin_command builtins[] = {
{"env", _env_builtin},
{"exit", _exit_builtin},
{NULL, NULL}
};

if (array_of_tokens == NULL || array_of_tokens[0] == NULL)
return (0);



for (builtin = 0; builtins[builtin].name != NULL; builtin++)
{
if (strcmp(array_of_tokens[0], builtins[builtin].name) == 0)
return (1);
}

return (0);
}

/**
* builin_handler - Execute a built-in command.
*
* @array_of_tokens: The command array.
*
* Return: The exit code of the executed built-in, or 0 if not found.
*/
int builin_handler(char **array_of_tokens)
{
int builtin;
const struct builtin_command builtins[] = {
{"env", _env_builtin},
{"exit", _exit_builtin},
{NULL, NULL}
};

if (array_of_tokens == NULL || array_of_tokens[0] == NULL)
return (0);



for (builtin = 0; builtins[builtin].name != NULL; builtin++)
{
if (strcmp(array_of_tokens[0], builtins[builtin].name) == 0)
return (builtins[builtin].function(array_of_tokens));
}

return (0);
}
