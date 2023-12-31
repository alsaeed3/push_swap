/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:05:23 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/11 23:12:22 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;
	int		len;

	len = ft_lstsize(*stack);
	if (*stack && len != 1)
	{
		tmp = *stack;
		last = ft_lst_last(*stack);
		*stack = (*stack)->next;
		last->next = tmp;
		last->next->next = NULL;
	}
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
