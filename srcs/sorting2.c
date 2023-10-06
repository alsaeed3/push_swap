/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:26 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/06 20:03:45 by alsaeed          ###   ########.fr       */
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

void	ft_index_min(t_list **stack)
{
	t_list		*tmp;
	int			data[5];
	int			index[5] = {-1, -1, -1, -1, -1};
	int			min;
	int			i;
	int			j;
	int k;
	i = 0;
	min = 2147483647;
	tmp = *stack;
	while (i < 5)
	{
		data[i] = (*stack)->index;
		*stack = (*stack)->next;
		i++;
	}
	*stack = tmp;
	i = 0;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (data[i] <= min && index[i] == -1)
			{
				k = i;
				min = data[i];
				printf("--------->%d\n", i);
			}
			i++;
		}
		printf(">%d, %d\n", k, j);
		index[k] = j;
		j++;
	}
	i = 0;
	while (i < 5)
	{
		printf("-->%d\n", index[i]);
		i++;
	}
}

void	get_min_pb(t_list **stack_a, t_list **stack_b)
{
	int		dist;
	t_list	*tmp;

	dist = 0;
	tmp = *stack_a;
	while (*stack_a)
	{
		printf(">\n");
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			while ((*stack_a)->distance > 0)
			{
				ra(stack_a);
				(*stack_a)->distance--;
			}
			pb(stack_a, stack_b);
		}
		
		*stack_a = (*stack_a)->next;
	}
	printf("---->\n");
	*stack_a = tmp;
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
		first_node = curr->index;
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

void	five_nodes_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;

	curr = NULL;
	if (*stack_a)
	{
		// curr = *stack_a;
		// while (curr != NULL)
		// {
		// 	printf("%d\n", curr->index);
		// 	curr = curr->next;
		// }
		printf("ft_index_min\n");
		ft_index_min(stack_a);
		printf("get_min_pb\n");
		get_min_pb(stack_a, stack_b);
		printf("ft_index_min\n");
		ft_index_min(stack_a);
		// curr = *stack_a;
		// while (curr != NULL)
		// {
		// 	printf("%d\n", curr->index);
		// 	curr = curr->next;
		// }
		printf("get_min_pb\n");
		get_min_pb(stack_a, stack_b);
		// curr = *stack_a;
		// while (curr != NULL)
		// {
		// 	printf("%d\n", curr->index);
		// 	curr = curr->next;
		// }
		printf("three_nodes_sort\n");
		three_nodes_sort(stack_a);
		if ((*stack_b)->index < (*stack_b)->next->index)
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}