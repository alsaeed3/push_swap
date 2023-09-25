/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/25 18:22:07 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

//void ft_putnbr(int n)
//{
//    if (n > 9)
//        ft_putnbr(n / 10);
//    write(1, &"0123456789"[n % 10], 1);
//}

void parse_nonnum_arg(char **s)
{
    int j;
    int i;

    j = 1;
    while (s[j])
    {
        i = 0;
        while (s[j][i])
        {
            if (s[j][i] != ' ' && !(s[j][i] >= '\t' && s[j][i] <= '\r') \
                && !(s[j][i] == '-' || s[j][i] == '+') \
                && !(s[j][i] >= '0' && s[j][i] <= '9'))
            {
                write(1, "Error\n", 6);
                exit (1);
            }
            i++;
        }
        j++;
    }
}

void parse_dup_arg(char **s)
{
	int i;
	int j;

    i = 1;
	j = 0;
    while (s[i])
    {
		j = i + 1;
		while (s[j])
		{
			printf("i: %d\nj: %d\n", ft_atoi(s[i]), ft_atoi(s[j]));
        	if (ft_atoi(s[i]) == ft_atoi(s[j]))	
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
        i++;
    }
}

int main (int ac, char **av)
{
    int j;
    int i;
    // t_node *head;

    j = 1;
    i = 0;
    parse_nonnum_arg(av);
	parse_dup_arg(av);
    // head->data = NULL;
    // head->next = NULL;
    // while (i < (ac - 1))
    // {
    //    t_node *arg = (t_node *)malloc(sizeof(t_node *) * 1);
        
    //    i++;
    // }
    return (0);
}
