/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:40:08 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/04 16:07:07 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* USED FUNCTIONS */
int		space_arg(char **s);
int		char_no(char **av);
char	*ft_strjoin_sp(int ac, char **av);
int		parse_nonnum_arg(char **av);
int		parse_dup_arg(char **s);
void 	parse_args(int ac, char **av);
t_list	*make_stack(char **str_arr);
char	**get_array(int ac, char **av);
void	init_stack_a(int ac, char **av, t_list *stack_a);

#endif