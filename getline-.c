#include "main.h"

/**
* _getline - Read a line from standard input.
*
* Description:
*     function reads a line of text from standard input stream (stdin).
*
* @input: A pointer to a character pointer that will store the input line.
* @bytes_allocated: A pointer to size of allocated memory
* @status: The exit status to be used in case of failure.
*
* Return:
*     On success, returns no of characters read (including newline).
*     On failure, it returns -1.
*/
ssize_t _getline(char **input, size_t *bytes_allocated, int status)
{
ssize_t read_chars;

/* Display a prompt if input is from a terminal. */
prompt();

do {
read_chars = getline(input, bytes_allocated, stdin);

/* Check for read errors or end-of-file. */
if (read_chars == -1)
{
/* Free allocated memory. */
free(*input);

/* Print a newline if input is from a terminal. */
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", strlen("\n"));

/* Exit with the specified status code. */
exit(status);
}

} while (read_chars == 0);  /* Continue until a non-empty line is read. */

return (read_chars);
}
