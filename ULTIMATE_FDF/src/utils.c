/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:22:35 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/17 14:53:05 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count(char *str, char characters)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != characters)
		{
			count++;
			while (str[i] && str[i] != characters)
				i++;
		}
		else if (str[i] == characters)
			i++;
	}
	return (count);
}
