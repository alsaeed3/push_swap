/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/11 21:21:34 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

char	**get_array(int ac, char **av)
{
	char	*str;
	char	**array;

	str = NULL;
	array = NULL;
	str = ft_strjoin_sp(ac, av);
	array = ft_split(str, ' ');
	free (str);
	str = NULL;
	if (ft_array_size(array) <= 1)
		exit (0);
	return (array);
}

int		find_highest_index(t_list *stack_a)
{
	t_list	*curr;
	int		max;

	curr = stack_a;
	max = -2147483648;
	while (curr)
	{
		if (curr->index >= max)
			max = curr->index;
		curr = curr->next;
	}
	printf("%d\n", max);
	return (max);
}

int		find_max_bits(t_list *stack_a)
{
	int	max_bits;
	int temp;
	int	bits;
	t_list	*curr;

	max_bits = 0;
	curr = stack_a;
	while (curr->next)
	{
		temp = curr->data;
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

void	multi_nodes_sort(t_list **stack_a, t_list **stack_b)
{
	int bit_pos;
	int max_bits;
	int	bit;
	int b_size;
	int lst_size;
	int	i;

	lst_size = ft_lstsize(*stack_a);
	max_bits = find_max_bits(*stack_a);
	bit_pos = 0;
	b_size = 0;
	printf("1----->\n");
	while (bit_pos < max_bits)
	{
		printf("2----->\n");
		i = 0;
		printf("3----->\n");
		while (i < 7)
		{
			printf("%d@----->\n", i);
			bit = ((*stack_a)->index >> bit_pos) & 1;
			printf("$----->\n");
			if (bit == 0)
			{
				printf("&----->\n");
				pb(stack_a, stack_b);
			}
			else
			{
				printf("#----->\n");
				ra(stack_a);
			}
			printf("!----->\n");
			i++;
			printf("*----->\n");
		}
		printf("4----->\n");
		b_size = ft_lstsize(*stack_b);
		i = 0;
		printf("5----->\n");
		while (i < b_size)
		{
			pa(stack_a, stack_b);
			i++;
		}
		printf("6----->\n");
		bit_pos++;
	}		
	i++;
}

void	init_stacks(int ac, char **av, t_list *stack_a, t_list *stack_b)
{
	char	**array_str;

	array_str = get_array(ac, av);
	stack_a = init_stack_a(array_str);
	if (ft_is_sorted(stack_a) == 0)
	{
		ft_free_array(array_str);
		exit (0);
	}
	ft_index_stack(&stack_a, array_str);
	if (ft_lstsize(stack_a) == 2)
		sa(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		three_nodes_sort(&stack_a, 'a');
	else if (ft_lstsize(stack_a) > 3 && ft_lstsize(stack_a) < 7)
		fvs_nodes_sort(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) >= 7)
		multi_nodes_sort(&stack_a, &stack_b);
	printf("stack_a:\n");
	t_list	*curr = stack_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	printf("stack_b:\n");
	curr = stack_b;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	ft_free_array(array_str);
}

int main (int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		parse_args(ac, av);
		init_stacks(ac, av, stack_a, stack_b);
		ft_deallocate_lst(stack_a);
		ft_deallocate_lst(stack_b);
	}
	return (0);
}
