/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:58:36 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/17 16:45:51 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	absolute(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	my_pixel_put_img(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	x += OFFX;
	y += OFFY;
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	brasenham(float x, float y, float x1, float y1, t_fdf *data) // [1:1] [3:12]
{
	float	x_step;
	float	y_step;

	///////////ZOOM ONLY//////////////
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	///////////ISOMETRIC 3D//////////
	
	x_step = x1 - x; // 2
	y_step = y1 - y; // 11
	x_step /= max_of(absolute(x_step), absolute(y_step));
	y_step /= max_of(absolute(x_step), absolute(y_step));
	while ((int)(x - x1) || (int)(y - y1))
	{
		printf("\n\n x = %f, y = %f", x , y);
		my_pixel_put_img(data, x, y, 0xFF0000);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			brasenham(x, y, x + 1, y, data);
			brasenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}