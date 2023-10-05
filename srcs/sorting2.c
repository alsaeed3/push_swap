/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:26 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/05 19:39:19 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	continue_three_sort(int fir_node, int sec_node, int thi_node, \
		t_list **stack)
{
	if ((fir_node > sec_node) && (fir_node > thi_node) \
		&& (sec_node > thi_node))
	{
		ra(stack);
		sa(stack);
	}
	else if ((fir_node < sec_node) && (fir_node < thi_node) \
		&& (sec_node > thi_node))
	{
		rra(stack);
		sa(stack);
	}
	else if ((fir_node < sec_node) && (fir_node > thi_node) \
		&& (sec_node > thi_node))
		rra(stack);
}

void	three_nodes_sort(t_list	**stack)
{
	t_list *curr;
	int		first_node;
	int		second_node;
	int		third_node;

	if (*stack && (*stack)->next && (*stack)->next->next)
	{
		curr = *stack;
		first_node = curr->content;
		second_node = curr->next->content;
		third_node = curr->next->next->content;
		if ((first_node > second_node) && (first_node < third_node) \
			&& (second_node < third_node))
			sa(stack);
		else if ((first_node > second_node) && (first_node > third_node) \
			&& (second_node < third_node))
			ra(stack);
		else
			continue_three_sort(first_node, second_node, third_node, stack);
	}
}

// void	five_nodes_sort(t_list **stack)
// {
// 	if (*stack)
// 	{
		
// 	}
// }