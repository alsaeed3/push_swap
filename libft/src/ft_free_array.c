/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:33:05 by alsaeed           #+#    #+#             */
/*   Updated: 2023/10/04 16:05:48 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return;
	while (array[i])
	{
		if (!array[i])
			return;
		free (array[i]);
		array[i] = NULL;
		i++;
	}
	if (array)
	{
		free (array);
		array = NULL;
	}
}