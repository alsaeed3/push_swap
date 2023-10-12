/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:26 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/12 19:01:17 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*init_stack_a(char **str_arr)
{
	t_list	*head;
	int		i;
	int		error;

	head = NULL;
	i = 0;
	error = 0;
	while (str_arr[i])
	{
		head = ft_lstadd_back(head, ft_atoi(str_arr[i], &error));
		i++;
	}
	if (error == -1)
	{
		write(2, "Error\n", 6);
		ft_free_array(str_arr);
		ft_deallocate_lst(&head);
		exit (1);
	}
	return (head);
}

int	*ft_init_index(t_list *stack, int *index, int size)
{
	int	i;

	i = 0;
	index = malloc(sizeof(int) * ft_lstsize(stack));
	while (i < size)
	{
		index[i] = -1;
		i++;
	}
	return (index);
}

void	ft_index_stack_cont(t_list **stack, t_index *index, \
		char **str_array, int error)
{
	int	size;

	index->tmp = *stack;
	index->i = 0;
	size = ft_lstsize(*stack);
	if (error == -1)
	{
		write(2, "Error\n", 6);
		ft_free_array(str_array);
		ft_deallocate_lst(stack);
		exit (1);
	}
	while (index->i < size && *stack)
	{
		(*stack)->index = index->indeces[index->i];
		index->i++;
		*stack = (*stack)->next;
	}
	*stack = index->tmp;
	free(index->indeces);
}

void	ft_index_stack(t_list **stack, char **str_array)
{
	t_index	index;
	int		error;

	index.indeces = ft_init_index(*stack, index.indeces, ft_lstsize(*stack));
	index.i = 0;
	error = 0;
	while (index.i < ft_lstsize(*stack))
	{
		index.j = 0;
		index.min = 2147483647;
		while (index.j < ft_lstsize(*stack))
		{
			if (index.indeces[index.j] == -1 \
				&& ft_atoi(str_array[index.j], &error) <= index.min)
			{
				index.k = index.j;
				index.min = ft_atoi(str_array[index.j], &error);
			}
			index.j++;
		}
		index.indeces[index.k] = index.i;
		index.i++;
	}
	ft_index_stack_cont(stack, &index, str_array, error);
}

void	get_min_pb(t_list **stack_a, t_list **stack_b)
{
	t_index	index;

	index.median = ft_lstsize(*stack_a) - 4;
	index.i = 0;
	index.lstsize = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index > index.median)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}
