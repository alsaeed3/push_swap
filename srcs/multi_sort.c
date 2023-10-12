/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:26 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/12 21:12:47 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	fvs_nodes_sort(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
	{
		get_min_pb(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 3)
			three_nodes_sort(stack_a, 'a');
		if (ft_lstsize(*stack_b) == 1)
			pa(stack_a, stack_b);
		else if (ft_lstsize(*stack_b) == 2)
		{
			if ((*stack_b)->data < (*stack_b)->next->data)
				sb(stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
		else if (ft_lstsize(*stack_b) == 3)
		{
			three_nodes_sort(stack_b, 'b');
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
		}
	}
}

int	find_max_bits(t_list *stack_a)
{
	int		max_bits;
	int		temp;
	int		bits;
	t_list	*curr;

	max_bits = 0;
	curr = stack_a;
	while (curr->next)
	{
		temp = curr->index;
		bits = 0;
		while (temp > 0)
		{
			bits++;
			temp >>= 1;
		}
		if (bits > max_bits)
			max_bits = bits;
		curr = curr->next;
	}
	return (max_bits);
}

t_multi_sort	init_multi(t_list *stack_a)
{
	t_multi_sort	multi;

	multi.lst_size = ft_lstsize(stack_a);
	multi.max_bits = find_max_bits(stack_a);
	multi.bit_pos = 0;
	multi.b_size = 0;
	return (multi);
}

void	multi_nodes_sort(t_list **stack_a, t_list **stack_b)
{
	t_multi_sort	multi;

	multi = init_multi(*stack_a);
	while (multi.bit_pos < multi.max_bits)
	{
		multi.i = 0;
		while (multi.i < multi.lst_size)
		{
			multi.bit = ((*stack_a)->index >> multi.bit_pos) & 1;
			if (multi.bit == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			multi.i++;
		}
		multi.b_size = ft_lstsize(*stack_b);
		multi.i = 0;
		while (multi.i < multi.b_size)
		{
			pa(stack_a, stack_b);
			multi.i++;
		}
		multi.bit_pos++;
	}
	multi.i++;
}
