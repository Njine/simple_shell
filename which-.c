#include "main.h"

/**
* is_valid_path - Check if a filename is a valid path.
*
* @filename: The filename to check.
*
* Return: 1 if it's a valid path, 0 if not.
*/
int is_valid_path(char *filename)
{
size_t len = strlen(filename);

if (len >= strlen("../") && strncmp(filename, "../", strlen("../")) == 0)
return (1);

if (len >= strlen("./") && strncmp(filename, "./", strlen("./")) == 0)
return (1);

if (len >= strlen("/") && strncmp(filename, "/", strlen("/")) == 0)
return (1);

return (0);
}

/**
* filepath_creator - Create a file path from tokens and filename.
*
* @fpath: The created file path.
* @tokray: The tokens array.
* @filename: The filename.
* @token_index: The index to copy from tokens.
*/
void filepath_creator(char **fpath, char **tokray,
char *filename, int token_index)
{
size_t path_length = strlen(tokray[token_index]) + strlen(filename) + 2;
malloc_char(fpath, path_length, "_which Error: malloc failed for fpath");


strcpy(*fpath, tokray[token_index]);
strcat(*fpath, "/");
strcat(*fpath, filename);
}

/**
* _which - Locate an executable file in the PATH environment variable.
*
* @filename: The filename to locate.
*
* Return: The full path to the located file, or NULL if not found.
*/
char *_which(char *filename)
{
struct stat sb;
char *path_var, *delimiter, *fpath;
char **tokray;
int token_index, fpath_exist;

delimiter = ":";
path_var = _getenv("PATH");
if (path_var != NULL)
{
tokray = array_maker(path_var, delimiter);
if (tokray != NULL)
{
for (token_index = 0; tokray[token_index]; token_index++)
{
filepath_creator(&fpath, tokray, filename, token_index);
fpath_exist = stat(fpath, &sb);
if (fpath_exist == 0)
{
free_which(&path_var, tokray);
return (fpath);
}
free(fpath);
}
free_which(&path_var, tokray);
}
else
free(path_var);
}

fpath_exist = stat(filename, &sb);
if (fpath_exist == 0 && is_valid_path(filename))
return (strdup(filename));

return (NULL);
}
