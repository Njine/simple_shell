#include "main.h"

/**
* prompt - display a shell prompt
*/
void prompt(void)
{
if (isatty(STDIN_FILENO))
{
char prompt_text[] = "$ ";
write(STDOUT_FILENO, prompt_text, sizeof(prompt_text) - 1);
}
}
