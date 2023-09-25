/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/23 19:40:39 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

//int ft_atoi(char *s)
//{
//    int i;
//    int integer;
//    int sign;

//    i = 0;
//    integer = 0;
//    sign = 1;
//    while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
//        i++;
//    while (s[i] == '-' || s[i] == '+')
//    {
//        if (s[i] == '-')
//            sign *= -1;
//        i++;
//    }
//    while (s[i])
//        integer = integer * 10 + s[i++] - 48;
//    return (integer * sign);
//}

//void ft_putnbr(int n)
//{
//    if (n > 9)
//        ft_putnbr(n / 10);
//    write(1, &"0123456789"[n % 10], 1);
//}

void parse_nonnum_arg(int ac, char **av)
{
    int j;
    int i;
    
    j = 1;
    while (av[j])
    {
        i = 0;
        printf("%d\n", ft_atoi(av[j]));
        while (av[j][i])
        {
            if (av[j][i] != ' ' && !(av[j][i] >= '\t' && av[j][i] <= '\r') \
                && !(av[j][i] == '-' || av[j][i] == '+') \
                && !(av[j][i] >= '0' && av[j][i] <= '9'))
            {
                write(1, "Error\n", 6);
                exit (1);
            }
            i++;
        }
        j++;
    }
}

void check_dup(int *stack)
{
    int j;

    j = 0;
    while (stack[j])
    {
        if (stack[j] == stack[j])
        j++;
    }
}

int main (int ac, char **av)
{
    int j;
    int i;
    t_node *head;

    j = 1;
    i = 0;
    parse_nonnum_arg(ac, av);
    //head->data = NULL;
    //head->next = NULL;
    //while (i < (ac - 1))
    //{
    //    t_node *arg = (t_node *)malloc(sizeof(t_node *) * 1);
        
    //    i++;
    //}
    return (0);
}
