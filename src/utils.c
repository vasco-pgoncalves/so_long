#include "so_long.h"

int    new_line_check(char *s)
{
    int i;
    i = 0;

    while (s[i] == '\n')
        i++;
    while (s[i] != '\0')
    {
        if (s[i] == '\n' && s[i + 1] == '\n')
        {
            break ;
        }
        i++;
    }
    while (s[i] == '\n')
        i++;
    if (s[i] != '\0')
        return (0);
    return (1);
}