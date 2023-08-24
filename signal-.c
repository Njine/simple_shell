#include "main.h"

/**
* sigint_handler - handle signals
* @signal: signal
*
* Return: nothing
*/
void sigint_handler(int signal)
{
if (signal == SIGINT)
{
char newline = '\n';
char prompt_text[] = "$ ";

write(STDOUT_FILENO, &newline, 1);
write(STDOUT_FILENO, prompt_text, sizeof(prompt_text) - 1);
fflush(stdout);
}
}
