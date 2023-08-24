#include "main.h"

/**
* _fork - Create a child process and execute a command.
*
* This function creates a child process using fork() and executes a command
* with the given array of tokens in the child process using execve().
*
* @command: The path to the executable command.
* @array_of_tokens: array of strings containing  command and arguments.
*
* Return: Returns  exit status of child process on success or -1 on failure
*/
int _fork(char *command, char **array_of_tokens)
{
pid_t pid;
int status, is_execve_error;

pid = fork();
if (pid == -1)
{
perror("_fork() Error: fork child unable to create");
return (-1);
}

if (pid == 0)
{
is_execve_error = execve(command, array_of_tokens, __environ);
if (is_execve_error == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
free(command);

if (WIFEXITED(status))
{
status = WEXITSTATUS(status);
}
else
{

status = -1;
}

if (!isatty(STDIN_FILENO))
{
return (status);
}
}
return (0);
}



