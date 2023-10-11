/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:05:56 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/11 14:14:08 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

t_list	*init_stack_a(char **str_arr)
{
	t_list	*head;
	int		i;

	head = (t_list *)malloc(sizeof(t_list) * 1);
	head->data = ft_atoi(str_arr[0]);
	head->index = -1;
	head->next = NULL;
	i = 1;
	while(str_arr[i])
	{
		head = ft_lstadd_back(head, ft_atoi(str_arr[i]));
		i++;
	}
	return(head);
}

int		*ft_init_index(t_list *stack, int *index, int size)
{
	int i;

	i = 0;
	index = malloc(sizeof(int) * ft_lstsize(stack));
	while (i < size)
	{
		index[i] = -1;
		i++;
	}
	return (index);
}

void	ft_index_stack_cont(t_list **stack, t_index *index)
{
	int	size;
	
	index->tmp = *stack;
	index->i = 0;
	size = ft_lstsize(*stack);
	while (index->i < size && *stack)
	{
		(*stack)->index = index->indeces[index->i];
		index->i++;
		*stack = (*stack)->next;
	}
	*stack = index->tmp;
}

int		ft_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_index_stack(t_list **stack, char **str_array)
{
	t_index	index;

	index.indeces = ft_init_index(*stack, index.indeces, ft_lstsize(*stack));
	index.i = 0;
	while (index.i < ft_lstsize(*stack))
	{
		index.j = 0;
		index.min = 2147483647;
		while (index.j < ft_lstsize(*stack))
		{
			if (index.indeces[index.j] == -1 && ft_atoi(str_array[index.j]) <= index.min)
			{
				index.k = index.j;
				index.min = ft_atoi(str_array[index.j]);
			}
			index.j++;
		}
		index.indeces[index.k] = index.i;
		index.i++;
	}
	ft_index_stack_cont(stack, &index);
}

void	get_min_pb(t_list **stack_a, t_list **stack_b)
{
	t_index	index;

	index.median = ft_lstsize(*stack_a) - 4;
	index.i = 0;
	index.lstsize = ft_lstsize(*stack_a);
	while (index.lstsize > 3)
	{
		if ((*stack_a)->index > index.median)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			index.lstsize--;
		}
	}
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list *top;

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
	int		len;

	len = ft_lstsize(*stack);
	if (*stack && stack && len != 1)
	{
		last = ft_lst_last(*stack);
		if (last)
		{
			prelast = ft_lst_prelast(*stack);
			last->next = *stack;
			if (prelast)
				prelast->next = NULL;
			*stack = last;
		}
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
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

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
	// t_list	*curr;
	
	// curr = NULL;
	// printf("before ra --> stack_a:\n");
	// curr = *stack_a;
	// while (curr != NULL)
	// {
	// 	printf("%d, index: %d\n", curr->data, curr->index);
	// 	curr = curr->next;
	// }
	rotate(stack_a);
	// printf("after ra --> stack_a:\n");
	// curr = *stack_a;
	// while (curr != NULL)
	// {
	// 	printf("%d, index: %d\n", curr->data, curr->index);
	// 	curr = curr->next;
	// }
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

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
