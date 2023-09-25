/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:50 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/25 18:22:55 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int ft_atoi(char *s)
{
   int i;
   long int integer;
   int sign;

   i = 0;
   integer = 0;
   sign = 1;
   while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
       i++;
   while (s[i] == '-' || s[i] == '+')
   {
       if (s[i] == '-')
           sign *= -1;
       i++;
   }
   while (s[i])
   {
    	integer = integer * 10 + s[i++] - 48;
		if (((integer * sign) > 2147483647) || ((integer * sign) < -2147483648))
		{
			write(2, "Error: The passed argument is out of INT limits\n", 48);
			exit (1);
		}
   }
   return (integer * sign);
}
