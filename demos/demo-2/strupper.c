/*
** EPITECH PROJECT, 2024
** tek-workshop-makefiles
** File description:
** strupper
*/

#include <stdio.h>
#include <string.h>

void my_strupper(char *str)
{
    char *cpy = strdup(str);
    int len = strlen(cpy);

    for (int i = 0; i < len; i++) {
        cpy[i] = cpy[i] >= 'a' && cpy[i] <= 'z' ? cpy[i] - 32 : cpy[i];
    }
    printf("uppercase: \"%s\"\n", cpy);
}

