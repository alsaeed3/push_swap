/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:03:05 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/12 21:34:24 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	parse_nonnum_arg(char **s)
{
	int	j;
	int	i;

	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] != ' ' && !(s[j][i] == '-' || s[j][i] == '+') \
			&& !(s[j][i] >= '0' && s[j][i] <= '9'))
				return (-1);
			if ((s[j][i] == '+' || s[j][i] == '-' \
			|| (s[j][i] >= '0' && s[j][i] <= '9')) \
			&& (s[j][i + 1] == '+' || s[j][i + 1] == '-'))
				return (-1);
			if ((s[j][i] == '+' || s[j][i] == '-') \
			&& (s[j][i + 1] == ' ' || s[j][i + 1] == '\0'))
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int	parse_dup_arg(char **s)
{
	int	i;
	int	j;
	int	error;

	error = 0;
	i = ft_atoi(s[0], &error);
	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[i], &error) == ft_atoi(s[j], &error) && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (error);
}

void	parse_args(int ac, char **av)
{
	char	*str;
	char	**str_arr;

	if (ft_space_arg(av) == -1)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	str = ft_strjoin_sp(ac, av);
	str_arr = ft_split(str, ' ');
	free (str);
	if (parse_nonnum_arg(str_arr) == -1 || parse_dup_arg(str_arr) == -1)
	{
		ft_free_array(str_arr);
		write(2, "Error\n", 6);
		exit (1);
	}
	ft_free_array(str_arr);
}
