#include "main.h"

/**
* digit_counter - Count the number of digits in a number.
*
* @command_num: The number to count digits for.
*
* Return: The number of digits in the given number.
*/
int digit_counter(size_t command_num)
{
int digit_count = 1;

while (command_num > 9)
{
command_num /= 10;
digit_count++;
}

return (digit_count);
}
