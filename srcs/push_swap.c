/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/29 17:20:55 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	block2(int ac, char **av)
{
	
}

int main (int ac, char **av)
{
	// t_dll		*stack_a;
	// t_node		*curr;
	
	parse_args(ac, av);
	block2(ac, av);
	// stack_a = NULL;
	// make_dll(stack_a, av, ac);
	// curr = stack_a->head;
	// while (curr != NULL)
	// {
	// 	printf("%d\n", stack_a->head->data);
	// 	curr = curr->next;
	// }
	// deallocate_dllst(stack_a);
    return (0);
}
