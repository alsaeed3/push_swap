/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:05:56 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/09 19:44:58 by alsaeed          ###   ########.fr       */
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

	head = NULL;
	head = malloc(sizeof(t_list));
	if (!head)
		exit (1);
	head->data = ft_atoi(str_arr[0]);
	head->distance = 0;
	head->index = -1;
	head->next = NULL;
	i = 1;
	while(str_arr[i])
	{
		head = ft_lstadd_back(head, ft_atoi(str_arr[i]));
		i++;
	}
	return (head);
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

void	ft_index_stack_cont(t_index *index, t_list **stack)
{
	index->tmp = *stack;
	index->i = 0;
	while (index->i < 5 && *stack)
	{
		(*stack)->index = index->index[index->i];
		*stack = (*stack)->next;
		index->i++;
	}
	*stack = index->tmp;
}

void	ft_index_stack(t_list **stack, char **str_array)
{
	t_index	*index; 
	
	index->index = ft_init_index(*stack, index->index, ft_lstsize(stack));
	index->i = 0;
	while (index->i < ft_lstsize(stack))
	{
		index->j = 0;
		index->min = 2147483647;
		while (index->j < ft_lstsize(stack))
		{
			if (index->index[index->j] == -1 && ft_atoi(str_array[index->j]) <= index->min)
			{
				index->k = index->j;
				index->min = ft_atoi(str_array[index->j]);
			}
			index->j++;
		}
		index->index[index->k] = index->i;
		index->i++;
	}
	ft_index_stack_cont(index, stack);
}

void	get_min_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		distance;

	tmp = *stack_a;
	while (*stack_a)
	{
		// printf(">\n");
		if ((*stack_a)->index == 0)
		{
			// printf("(*stack_a)->distance = %d\n", (*stack_a)->distance);
			distance = (*stack_a)->distance - 1;
			// printf("*****>\n");
			while (distance > 0)
			{
				rra(stack_a);
				distance--;
				// printf ("distance = %d\n", distance);
			}
			pb(stack_a, stack_b);
		}
		
		*stack_a = (*stack_a)->next;
	}
	// printf("---->\n");
	*stack_a = tmp;
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list *push_node;
	
	if (*stack_2 == NULL)
		return ;
	push_node = *stack_2;
	*stack_2 = (*stack_2)->next;
	if (*stack_1 == NULL)
	{
		*stack_1 = push_node;
		push_node->next = NULL;	
	}
	else
	{
		push_node->next = *stack_1;
		*stack_1 = push_node;
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
	write(1, "rra\n", 4);
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
	write(1, "sa\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
