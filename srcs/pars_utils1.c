/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:03:05 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/28 18:39:00 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int space_arg(char **s)
{
	int i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (ft_isspace(s[i][j]) == 1)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		char_no(char **av)
{
	int		i;
	int		j;
	int		count;
	
	i = 1;
	count = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	*ft_strjoin_sp(int ac, char **av)
{
	char	*str;
	int		size;
	int		i;
	int		j;
	int		k;

	size = char_no(av) + ac - 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		exit (1);
	i = 1;
	k = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			str[k++] = av[i][j++];
		if (av[i + 1] != NULL)
			str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}

int parse_nonnum_arg(char **s)
{
    int j;
    int i;

    j = 0;
    while (s[j])
    {
        i = 0;
        while (s[j][i])
        {
            if (s[j][i] != ' ' && !(s[j][i] >= '\t' && s[j][i] <= '\r') \
                && !(s[j][i] == '-' || s[j][i] == '+') \
                && !(s[j][i] >= '0' && s[j][i] <= '9'))
                return (1);
            i++;
        }
        j++;
    }
	return (0);
}

int	parse_dup_arg(char **s)
{
	int i;
	int j;

    i = 0;
	j = 0;
    while (s[i])
    {
		while (s[j])
		{
        	if (ft_atoi(s[i]) == ft_atoi(s[j]) && i != j)	
				return (1);
			j++;
		}
        i++;
    }
	return (0);
}
