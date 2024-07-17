/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:46:18 by lucas             #+#    #+#             */
/*   Updated: 2024/07/17 14:51:22 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../src/get_next_line.h"

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	get_key(int key);
int		ft_count(char *str, char characters);
void	read_file(char *map_name, t_fdf *data);

#endif
