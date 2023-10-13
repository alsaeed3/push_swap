/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:40:08 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/13 16:13:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct cs_index
{
	int				*indeces;
	int				min;
	int				median;
	int				i;
	int				j;
	int				k;
	int				lstsize;
	t_list			*tmp;
}	t_index;
typedef struct s_multi_sort
{
	int				bit_pos;
	int				max_bits;
	int				bit;
	int				lst_size;
	int				b_size;
	int				i;	
}	t_multi_sort;

int				parse_nonnum_arg(char **av);
int				parse_dup_arg(char **s);
void			parse_args(int ac, char **av);
t_list			*init_stack_a(char **str_arr);
void			ft_index_stack_cont(t_list **stack, t_index *index, \
				char **str_array, int error);
void			ft_index_stack(t_list **stack, char **str_array);
void			get_min_pb(t_list **stack_a, t_list **stack_b);
int				ft_is_sorted(t_list *stack);
void			get_min_pb(t_list **stack_a, t_list **stack_b);
void			init_stacks(int ac, char **av, t_list **stack_a, \
							t_list **stack_b);
int				find_max_bits(t_list *stack_a);
t_multi_sort	init_multi(t_list *stack_a);
void			multi_nodes_sort(t_list **stack_a, t_list **stack_b);
void			push(t_list **stack_1, t_list **stack_2);
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_a, t_list **stack_b);
void			swap(t_list **stack);
void			sa(t_list **stack_a);
void			sb(t_list **stack_b);
void			ss(t_list **stack_a, t_list **stack_b);
void			rotate(t_list **stack);
void			ra(t_list **stack_a);
void			rb(t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b);
t_list			*ft_lst_prelast(t_list *stack);
void			reverse_rotate(t_list **stack);
void			rra(t_list **stack_a);
void			rrb(t_list **stack_b);
void			rrr(t_list **stack_a, t_list **stack_b);
void			three_nodes_sort(t_list	**stack, char flag);
void			three_nodes_sort_c(t_list **stack, char flag);
void			cont_three_sort1(t_list **stack, t_list *curr, char flag);
void			cont_three_sort2(t_list **stack, t_list *curr, char flag);
void			fvs_nodes_sort(t_list **stack_a, t_list **stack_b);

#endif