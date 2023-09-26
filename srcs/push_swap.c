/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/26 17:50:54 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int main (int ac, char **av)
{
	int			i;
    t_node		*head;
	t_dou_llst	*stack_a;

	if(ac == 1)
		return (0);
    parse_nonnum_arg(av);
	parse_dup_arg(av);
	head = create_head(ft_atoi(av[1]));
	stack_a = NULL;
	init_dllst(stack_a);
	i = 0;
	while (i < (ac - 1))
	{
    	t_node *arg = (t_node *)malloc(sizeof(t_node *) * 1);
		
    	i++;
	}
    return (0);
}
