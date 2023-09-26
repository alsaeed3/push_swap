/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:40:08 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/26 16:10:27 by alsaeed          ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*prev;
} 					t_node;

typedef struct		s_doubly_linked_list
{
	t_node			*head;
	t_node			*tail;
}					t_dou_llst;
/* USED FUNCTIONS */
void	parse_nonnum_arg(char **av);
void	parse_dup_arg(char **s);
t_node	*create_head(int integer);
void	init_dllst(t_dou_llst *lst);

#endif