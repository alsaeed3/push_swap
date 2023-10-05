/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:40:08 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/05 14:42:31 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* USED FUNCTIONS */
int		char_no(char **av);
char	*ft_strjoin_sp(int ac, char **av);
int		parse_nonnum_arg(char **av);
int		parse_dup_arg(char **s);
void 	parse_args(int ac, char **av);
char	**get_array(int ac, char **av);
void	init_stacks(int ac, char **av, t_list *stack_a, t_list *stack_b);
void	push(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
t_list	*ft_lst_prelast(t_list *stack);
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);

#endif