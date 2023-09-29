/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/29 18:11:02 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	block2(int ac, char **av)
{
	char	*str;
	char	**array_str;
	t_dll	*stack_a;

	// t_node	*curr;

	str = ft_strjoin_sp(ac, av);
	array_str = ft_split(str, ' ');
	free (str);
	stack_a = malloc(sizeof(t_dll));
	printf("hi");
	make_dll(stack_a, array_str, ac);
	// curr = stack_a->head;
	// while (curr != NULL)
	// {
	// 	printf("%d\n", stack_a->head->data);
	// 	curr = curr->next;
	// }
	// deallocate_dllst(stack_a);
}

int main (int ac, char **av)
{	
	parse_args(ac, av);
	block2(ac, av);
    return (0);
}
