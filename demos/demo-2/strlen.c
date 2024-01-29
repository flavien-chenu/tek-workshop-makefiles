/*
** EPITECH PROJECT, 2024
** tek-workshop-makefiles
** File description:
** strlen
*/


#include <stdio.h>

void my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL) {
        printf("error: null pointer\n");
        return;
    }
    while (str[len] != '\0') {
        len += 1;
    }
    printf("length: %d\n", len);
}
