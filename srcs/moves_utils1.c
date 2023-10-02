/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:05:25 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/02 19:26:51 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	malloc_node()

void	make_stack_a(t_list *stack_a, char **str_arr)
{
	t_list	*head;
	t_list	*curr;
	int		i;

	head = malloc(sizeof(t_list));
	head->content = ft_atoi(str_arr[0]);
	head->content = NULL;
	curr = 
	i = 1;
	while(str_arr[i])
	{
		
		head->next = malloc(sizeof(t_list));
		head->next->content = ft_atoi(str_arr[i]);
		head->next->next = NULL;
	}
}
