/*
** EPITECH PROJECT, 2024
** tek-workshop-makefiles
** File description:
** strlower
*/

#include <stdio.h>
#include <string.h>

void my_strlower(char *str)
{
    char *cpy = strdup(str);
    int len = strlen(cpy);

    for (int i = 0; i < len; i++) {
        cpy[i] = cpy[i] >= 'A' && cpy[i] <= 'Z' ? cpy[i] + 32 : cpy[i];
    }
    printf("lowercase: \"%s\"\n", cpy);
}
