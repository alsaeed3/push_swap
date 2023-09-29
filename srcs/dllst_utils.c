/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllst_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:00 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/28 15:44:26 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_dll(t_dll *lst)
{
	if (lst)
	{
		lst->head = malloc(sizeof(t_node));
		lst->tail = malloc(sizeof(t_node));
		lst->head->data = 0;
		lst->head->next = NULL;
		lst->head->prev = NULL;
		lst->tail->data = 0;
		lst->tail->next = NULL;
		lst->tail->prev = NULL;
	}
}

void	create_head_dll(t_node **head, int integer)
{
	(*head)->data = integer;
	(*head)->next = NULL;
	(*head)->prev = NULL;
}

void	insert_begin_dll(t_node **head, int integer)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (1);
	new_node->data = integer;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

void	insert_end_dll(t_node **tail, int integer)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (1);
	new_node->data = integer;
	new_node->next = NULL;
	new_node->prev = *tail;
	if (*tail != NULL)
		(*tail)->next = new_node;
	*tail = new_node;
}

void	insert_after_dll(t_node *node, int integer)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if(!new_node)
		exit (1);
	new_node->data = integer;
	new_node->prev = node;
	new_node->next = node->next;
	if (node->next != NULL)
		node->next->prev = new_node;
	node->next = new_node;
}

void	insert_before_dll(t_node *node, int integer)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (1);
	new_node->data = integer;
	new_node->prev = node->prev;
	new_node->next = node;
	if (node->prev != NULL)
		node->prev->next = new_node;
	node->prev = new_node;
}

void	make_dll(t_dll *stack, char **av, int ac)
{
	int i;

	init_dll(stack);
	stack = malloc(sizeof(t_dll));
	if (!stack)
		exit (1);
	printf("%s,%d\n", av[1], ft_atoi(av[1]));
	create_head_dll(&stack->head, ft_atoi(av[1]));
	i = 2;
	while (i < ac)
	{
		printf("%s,%d\n", av[i], ft_atoi(av[i]));
		insert_end_dll(&stack->tail, ft_atoi(av[i]));
		i++;
	}
}

void deallocate_dllst(t_dll *stack)
{
	t_node *curr;

	if (stack->head == NULL)
		return;
	curr = stack->head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free (curr);
	stack->head = NULL;
	stack->tail = NULL;
}
