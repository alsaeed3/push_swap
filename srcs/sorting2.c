/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:26 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/09 19:48:07 by alsaeed          ###   ########.fr       */
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

// void	ft_index_min(t_list **stack)
// {
// 	t_list		*tmp;
// 	int			distance;
// 	int			min;
	
// 	min = 2147483647;
// 	distance = 0;
// 	tmp = *stack;
// 	while (*stack)
// 	{
// 		if ((*stack)->data <= min)
// 			min = (*stack)->data;
// 		*stack = (*stack)->next;
// 	}
// 	*stack = tmp;
// 	while (*stack)
// 	{
// 		distance++;
// 		if ((*stack)->data == min)
// 		{
// 			(*stack)->index = 0;
// 			(*stack)->distance = distance;
// 			printf("(*stack_a)->distance = %d\n", (*stack)->distance);
// 		}
// 		*stack = (*stack)->next;
// 	}
// 	*stack = tmp;
// }

// void	get_min_pb(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int		distance;

// 	tmp = *stack_a;
// 	while (*stack_a)
// 	{
// 		// printf(">\n");
// 		if ((*stack_a)->index == 0)
// 		{
// 			// printf("(*stack_a)->distance = %d\n", (*stack_a)->distance);
// 			distance = (*stack_a)->distance - 1;
// 			// printf("*****>\n");
// 			while (distance > 0)
// 			{
// 				ra(stack_a);
// 				distance--;
// 				// printf ("distance = %d\n", distance);
// 			}
// 			pb(stack_a, stack_b);
// 		}
		
// 		*stack_a = (*stack_a)->next;
// 	}
// 	// printf("---->\n");
// 	*stack_a = tmp;
// }

void	three_nodes_sort(t_list	**stack)
{
	t_list *curr;
	int		first_node;
	int		second_node;
	int		third_node;

	if (*stack && (*stack)->next && (*stack)->next->next)
	{
		curr = *stack;
		first_node = curr->data;
		second_node = curr->next->data;
		third_node = curr->next->next->data;
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

void	five_nodes_sort(t_list **stack_a, t_list **stack_b, char **str_array)
{
	//t_list	*curr;
	printf("five_nodes_sort\n");
	//curr = NULL;
	if (*stack_a)
	{
		// curr = *stack_a;
		// while (curr != NULL)
		// {
		// 	printf("%d\n", curr->index);
		// 	curr = curr->next;
		// }
		// printf("ft_index_min\n");
		ft_index_stack(stack_a, str_array);
		// printf("get_min_pb\n");
		get_min_pb(stack_a, stack_b);
		// printf("ft_index_min\n");
		if (ft_lstsize(*stack_a) == 3)
			three_nodes_sort(stack_a);
		if ((*stack_b)->data < (*stack_b)->next->data)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}