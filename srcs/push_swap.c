/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/04 16:12:03 by alsaeed          ###   ########.fr       */
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

void	init_stack_a(int ac, char **av, t_list *stack_a)
{
	char	**array_str;
	t_list	*curr;
	// int		i;

	array_str = get_array(ac, av);
	// for (int i = 0; array_str[i]; i++)
	// 	printf("%s, ", array_str[i]);
	stack_a = make_stack(array_str);
	ft_free_array(array_str);
	curr = stack_a;
	while (curr != NULL)
	{
		printf("%d\n", curr->content);
		curr = curr->next;
	}
}

int main (int ac, char **av)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (ac != 1)
	{
		parse_args(ac, av);
		init_stack_a(ac, av, stack_a);
		ft_deallocate_lst(stack_a);
	}
	return (0);
}
