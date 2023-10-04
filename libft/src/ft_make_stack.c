/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:04:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/04 16:07:44 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_make_stack(char **str_arr)
{
	t_list	*head;
	int		i;

	head = malloc(sizeof(t_list));
	if (!head)
		exit (1);
	head->content = ft_atoi(str_arr[0]);
	head->next = NULL;
	i = 1;
	while(str_arr[i])
	{
		head = ft_lstadd_back(head, ft_atoi(str_arr[i]));
		i++;
	}
	return (head);
}