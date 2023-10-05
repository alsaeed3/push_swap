/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:05:22 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/05 14:43:50 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*ft_lst_prelast(t_list *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prelast;

	if (*stack)
	{
		last = ft_lst_last(*stack);
		prelast = ft_lst_prelast(*stack);
		last->next = *stack;
		prelast->next = NULL;
		*stack = last;
	}
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rra\n", 4);
}
