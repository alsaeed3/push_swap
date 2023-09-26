/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:03:05 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/26 17:43:19 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
                write(2, "\033[1;31mError\n\033[0m", 17);
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
        	if (ft_atoi(s[i]) == ft_atoi(s[j]))	
			{
				write(2, "\033[1;31mError\n\033[0m", 17);
				exit(1);
			}
			j++;
		}
        i++;
    }
}
