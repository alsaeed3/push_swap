/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:50 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/11 20:21:31 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int ft_atoi(char *s)
{
	int i;
	long int integer;
	int sign;

	i = 0;
	integer = 0;
	sign = 1;
	while (s[i] == ' ')
		i++;
    if (s[i] == '-')
       sign *= -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' )
	{
		if (s[i] == '-' || s[i] == '+')
			ft_error_exit();
		integer = integer * 10 + s[i] - 48;
		if (((integer * sign) > 2147483647) || ((integer * sign) < -2147483648))
			ft_error_exit();
		i++;
	}
	return (integer * sign);
}
