/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/05 15:04:23 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

char	**get_array(int ac, char **av)
{
	char	*str;
	char	**array;

	str = NULL;
	array = NULL;
	str = ft_strjoin_sp(ac, av);
	array = ft_split(str, ' ');
	free (str);
	str = NULL;
	if (ft_array_size(array) <= 1)
		exit (0);
	return (array);
}

void	init_stacks(int ac, char **av, t_list *stack_a, t_list *stack_b)
{
	char	**array_str;
	t_list	*curr;
	
	array_str = get_array(ac, av);
	stack_a = ft_make_stack(array_str);
	ft_free_array(array_str);
	curr = stack_a;
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	curr = stack_a;
	printf("stack_a:\n");
	while (curr != NULL)
	{
		printf("%d\n", curr->content);
		curr = curr->next;
	}
	printf("stack_b:\n");
	curr = stack_b;
	while (curr != NULL)
	{
		printf("%d\n", curr->content);
		curr = curr->next;
	}
}

int main (int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		parse_args(ac, av);
		init_stacks(ac, av, stack_a, stack_b);
		ft_deallocate_lst(stack_a);
	}
	return (0);
}
