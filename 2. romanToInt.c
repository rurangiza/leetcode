/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2. romanToInt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:08:53 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/09 19:59:05 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////

void    handleSpecialCases(char *s, char type, int *result, int *index);

int romanToInt(char * s){
    int result = 0;
    int i = 0;

    while (s[i])
    {
        if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
            handleSpecialCases(s, s[i], &result, &i);
        else if (s[i] == 'V')
            result += 5;
        else if (s[i] == 'L')
            result += 50;
        else if (s[i] == 'D')
            result += 500;
        else if (s[i] == 'M')
            result += 1000;
        i++;
    }
    return (result);
}

void    handleSpecialCases(char *s, char type, int *result, int *index)
{
    int     base = 1;
    char    *modifier[3] = {"VX", "LC", "DM"};
    int     group = 0;

    if (type == 'X')
    {
        base *= 10;
        group = 1;
    }
    else if (type == 'C')
    {
        base *= 100;
        group = 2;
    }
    if (!s[*index + 1] || (s[*index + 1] != modifier[group][0] && s[*index + 1] != modifier[group][1]))
        *result += 1 * base;
    else
    {
        if (s[*index + 1] == modifier[group][0])
            *result += 4 * base;
        else if (s[*index + 1] == modifier[group][1])
            *result += 9 * base;
        *index += 1;
    }
}

///////////////////////////////////////////////////////////////////////////////
int     isRomanNum(char *str);

int main(void)
{
    char number[15];
    while (1)
    {
        printf("\033[1mEnter a roman numeral number:\033[0m \n> ");
        scanf("%s", number);
        if (strncmp("stop", number, 4) == 0)
            break ;
        if (!isRomanNum(number))
            printf("\033[31mNot a roman numeral\033[0m\n");
        else
            printf("\033[32mOutput: %d\033[0m\n", romanToInt(number));
    }
    return (EXIT_SUCCESS);
}

int isRomanNum(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != 'I'
            && str[i] != 'V'
            && str[i] != 'X'
            && str[i] != 'L'
            && str[i] != 'C'
            && str[i] != 'D'
            && str[i] != 'M')
        return (0);
    }
    return (1);
}