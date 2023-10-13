/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/13 16:06:34 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	init_stacks(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	char	**array_str;

	array_str = ft_get_array(ac, av);
	*stack_a = init_stack_a(array_str);
	ft_index_stack(stack_a, array_str);
	if (ft_is_sorted(*stack_a) == 0)
	{
		ft_free_array(array_str);
		ft_deallocate_lst(stack_a);
		exit (0);
	}
	ft_free_array(array_str);
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		three_nodes_sort(stack_a, 'a');
	else if (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) < 7)
		fvs_nodes_sort(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) >= 7)
		multi_nodes_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		parse_args(ac, av);
		init_stacks(ac, av, &stack_a, &stack_b);
		ft_deallocate_lst(&stack_a);
		ft_deallocate_lst(&stack_b);
	}
	return (0);
}
