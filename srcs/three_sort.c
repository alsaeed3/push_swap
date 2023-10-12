/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:26 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/12 20:31:32 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	three_nodes_sort(t_list **stack, char flag)
{
	if (*stack && (*stack)->next && (*stack)->next->next)
		three_nodes_sort_c(stack, flag);
}

void	three_nodes_sort_c(t_list **stack, char flag)
{
	t_list	*curr;

	curr = *stack;
	if ((curr->data > curr->next->data) \
			&& (curr->data < curr->next->next->data) \
			&& (curr->next->data < curr->next->next->data))
	{
		if (flag == 'a')
			sa(stack);
		else if (flag == 'b')
			rrb(stack);
	}
	else if ((curr->data < curr->next->data) \
		&& (curr->data < curr->next->next->data) \
		&& (curr->next->data < curr->next->next->data))
	{
		if (flag == 'b')
		{
			rb(stack);
			sb(stack);
		}
	}
	else
		cont_three_sort1(stack, curr, flag);
}

void	cont_three_sort1(t_list **stack, t_list *curr, char flag)
{
	if ((curr->data > curr->next->data) \
		&& (curr->data > curr->next->next->data) \
		&& (curr->next->data < curr->next->next->data))
	{
		if (flag == 'a')
			ra(stack);
		else if (flag == 'b')
		{
			rrb(stack);
			sb(stack);
		}
	}
	else if ((curr->data > curr->next->data) \
		&& (curr->data > curr->next->next->data) \
		&& (curr->next->data > curr->next->next->data))
	{
		if (flag == 'a')
		{
			ra(stack);
			sa(stack);
		}
	}
	else
		cont_three_sort2(stack, curr, flag);
}

void	cont_three_sort2(t_list **stack, t_list *curr, char flag)
{
	if ((curr->data < curr->next->data) \
		&& (curr->data < curr->next->next->data) \
		&& (curr->next->data > curr->next->next->data))
	{
		if (flag == 'a')
		{
			rra(stack);
			sa(stack);
		}
		else if (flag == 'b')
			rb(stack);
	}
	else if ((curr->data < curr->next->data) \
		&& (curr->data > curr->next->next->data) \
		&& (curr->next->data > curr->next->next->data))
	{
		if (flag == 'a')
			rra(stack);
		else if (flag == 'b')
			sb(stack);
	}
}
