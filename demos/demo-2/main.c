/*
** EPITECH PROJECT, 2024
** tek-workshop-makefiles
** File description:
** main
*/

#include <stdio.h>
#include "str.h"

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        printf("---- [%s] ----\n", av[i]);
        my_strlen(av[i]);
        my_strlower(av[i]);
        my_strupper(av[i]);
    }
    return (0);
}
