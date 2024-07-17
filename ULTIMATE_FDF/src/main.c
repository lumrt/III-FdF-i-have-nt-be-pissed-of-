/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:05:19 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/17 14:58:02 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "fdf.h"

void	get_key(int key)
{
	printf("%d", key);
}

int	main(int ac, char **av)
{
	t_fdf	*data;
	int		i;
	int		j;

	if (ac != 2)
	{
		printf("./fdf testmaps/map.fdf (to delete it used the stdio printf)");
		exit (1);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
