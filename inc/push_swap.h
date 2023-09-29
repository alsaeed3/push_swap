/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:40:08 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/29 14:35:58 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct 		s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
} 					t_node;

typedef struct		s_doubly_linked_list
{
	t_node			*head;
	t_node			*tail;
}					t_dll;
/* USED FUNCTIONS */
int		space_arg(char **s);
int		char_no(char **av);
char	*ft_strjoin_sp(int ac, char **av);
int		parse_nonnum_arg(char **av);
int		parse_dup_arg(char **s);
void 	parse_args(int ac, char **av);
void	init_dll(t_dll *lst);
void	create_head_dll(t_node **head, int integer);
void	insert_begin_dll(t_node **head, int integer);
void	insert_end_dll(t_node **tail, int integer);
void	insert_after_dll(t_node *node, int integer);
void	insert_before_dll(t_node *node, int integer);
void	make_dll(t_dll *stack, char **av, int ac);
void	deallocate_dllst(t_dll *stack);


#endif