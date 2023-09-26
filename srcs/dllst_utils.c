/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllst_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:00 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/26 16:48:18 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*create_head(int integer)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
	{
		write(2, "Memory allocation for the head node has failed!!\n", 49);
		exit (1);
	}
	head->data = integer;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	init_dllst(t_dou_llst *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}
