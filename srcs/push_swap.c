/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:02:47 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/28 18:37:51 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void free_and_exit(void)
{
	// free char **str_arr
	write(2, "\033[1;31mError\ndup\n\033[0m", 21);
	exit (1);
}

int main (int ac, char **av)
{
	char	*str;
	char	**str_arr;
	// t_dll		*stack_a;
	// t_node		*curr;
	
	if (ac == 1)
		return (0);
	if (space_arg(av) == 1)
		return (1);
	str = ft_strjoin_sp(ac, av);
	str_arr = ft_split(str, ' ');
	if (parse_nonnum_arg(str_arr) == 1)
	{
		write(2, "Error\nnonnum\n", 13);
		exit (1);
	}
	if (parse_dup_arg(str_arr) == 1)
	{
		write(2, "Error\ndup\n", 10);
		exit (1);
	}
	// stack_a = NULL;
	// make_dll(stack_a, av, ac);
	// curr = stack_a->head;
	// while (curr != NULL)
	// {
	// 	printf("%d\n", stack_a->head->data);
	// 	curr = curr->next;
	// }
	// deallocate_dllst(stack_a);
    return (0);
}
