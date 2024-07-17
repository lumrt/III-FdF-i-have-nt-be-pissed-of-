/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:08:40 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/17 15:03:58 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int	get_height(char *map_name)
{
	int		fd;
	int		height;

	fd = open(map_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	get_width(char *map_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(map_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = ft_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_tab(int *z_line, char *line)
{
	char	**n;
	int		i;

	n = ft_split(line, ' ');
	i = 0;
	while (n[i])
	{
		z_line[i] = ft_atoi(n[i]);
		free(n[i]);
		i++;
	}
	free(n);
}

void	read_file(char *map_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(map_name);
	data->width = get_width(map_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(map_name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_tab(data->z_matrix[i], line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
