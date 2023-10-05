/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:05:22 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/05 14:30:15 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack)
	{
		tmp = *stack;
		last = ft_lst_last(*stack);
		*stack = (*stack)->next;
		last->next = tmp;
		tmp->next = NULL;
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
