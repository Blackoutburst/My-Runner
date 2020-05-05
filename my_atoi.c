/*
** EPITECH PROJECT, 2019
** my_get_nbr
** File description:
** get a number from a string
*/

#include "include/function.h"

int count_number(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9')
            count++;
        i++;
    }
    return (count);
}

int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int is_operator(char c)
{
    if (c == '-' || c == '+')
        return (1);
    else
        return (0);
}

int check_if_is_neg(char const *str)
{
    int minus_number = 0;
    int i = 0;

    while (is_operator(str[i])) {
        if (str[i] == '-')
            minus_number++;
        i++;
    }
    if (minus_number % 2 == 1)
        return (-1);
    else
        return (1);
}

int my_atoi(char const *str)
{
    int neg = check_if_is_neg(str);
    int number = 0;
    int i = 0;
    int pow = 1;

    for (int j = 0; j < count_number(str) - 1; j++)
        pow = pow * 10;
    while (str[i]) {
        if (is_number(str[i])) {
            number += (str[i] - 48) * pow;
            pow = pow / 10;
        }
        i++;
    }
    number = number * neg;
    return (number);
}
