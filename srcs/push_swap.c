/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/02 19:13:39 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	block2(int ac, char **av)
{
	char	*str;
	char	**array_str;
	// t_list	stack_a;
	// t_list	*curr;
	// int		i;

	if (ac == 2)
		exit (0);
	str = ft_strjoin_sp(ac, av);
	array_str = ft_split(str, ' ');
	// i = 0;
	// while (array_str[i])
	// 	printf("%s, ", array_str[i++]);
	// for(int i = 0; array_str[i]; i++)
	// 	printf("%s, ", array_str[i]);
	// printf("\n");
	// free (str);
	// str = NULL;
	// make_stack_a(&stack_a, array_str);
	// curr = stack_a.head;
	// while (curr->next != NULL)
	// {
	// 	printf("%d\n", curr->data);
	// 	printf("%p\n", curr);
	// 	curr = curr->next;
	// }
	// deallocate_dllst(&stack_a);
}

int main (int ac, char **av)
{
	if (ac != 1)
	{
		parse_args(ac, av);
		// block2(ac, av);
	}
	return (0);
}
