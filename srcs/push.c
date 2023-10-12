/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:05:25 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/12 14:00:46 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*top;

	if (*stack_2)
	{
		top = *stack_2;
		*stack_2 = top->next;
		top->next = *stack_1;
		*stack_1 = top;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
