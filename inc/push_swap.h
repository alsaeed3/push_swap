/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:40:08 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/22 23:03:54 by alsaeed          ###   ########.fr       */
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
} 					t_node;

/* USED FUNCTIONS */
void	parse_nonnum_arg(int ac, char **av);

#endif