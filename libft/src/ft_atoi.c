/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:50 by alsaeed           #+#    #+#             */
/*   Updated: 2023/09/26 17:43:35 by alsaeed          ###   ########.fr       */
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
			write(2, "\033[1;31mError\n\033[0m", 17);
			exit (1);
		}
   }
   return (integer * sign);
}
