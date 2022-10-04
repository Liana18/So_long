/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:24:41 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 19:37:37 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_mlx_data *mlx)
{
	mlx->sz_i = 60;
	mlx->sz_j = 60;
	mlx->c_c = mlx_xpm_file_to_image(mlx->mlx, "./img/collectible_c.xpm",
			&mlx->sz_i, &mlx->sz_j);
	mlx->p_p = mlx_xpm_file_to_image(mlx->mlx, "./img/player_p.xpm",
			&mlx->sz_i, &mlx->sz_j);
	mlx->w_1 = mlx_xpm_file_to_image(mlx->mlx, "./img/wall_1.xpm",
			&mlx->sz_i, &mlx->sz_j);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "./img/exit_e.xpm",
			&mlx->sz_i, &mlx->sz_j);
	mlx->fon_0 = mlx_xpm_file_to_image(mlx->mlx, "./img/fon_0.xpm",
			&mlx->sz_i, &mlx->sz_j);
	mlx->enemy_z = mlx_xpm_file_to_image(mlx->mlx, "./img/enemy_z.xpm",
			&mlx->sz_i, &mlx->sz_j);
	mlx->enemy_y = mlx_xpm_file_to_image(mlx->mlx, "./img/enemy_y.xpm",
			&mlx->sz_i, &mlx->sz_j);
}

//---------------------------------------------------------------------------//

void	draw_map(t_mlx_data *mlx, char ch, size_t j, size_t i)
{
	if (ch == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->w_1,
			j * IMG_SZ, i * IMG_SZ);
	else
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->fon_0,
			j * IMG_SZ, i * IMG_SZ);
		if (ch == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->c_c,
				j * IMG_SZ, i * IMG_SZ);
		else if (ch == 'P')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->p_p,
				j * IMG_SZ, i * IMG_SZ);
		else if (ch == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
				j * IMG_SZ - 13, i * IMG_SZ);
		else if (ch == 'Y')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->enemy_y,
				j * IMG_SZ, i * IMG_SZ);
		else if (ch == 'Z')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->enemy_z,
				j * IMG_SZ, i * IMG_SZ);
	}
}

//---------------------------------------------------------------------------//

void	send_to_draw(t_mlx_data *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < mlx->line_count)
	{
		j = 0;
		while (j < mlx->line_len)
		{
			draw_map(mlx, mlx->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
