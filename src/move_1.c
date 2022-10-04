/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:25:38 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 19:39:28 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_move(int direction, t_mlx_data *mlx)
{
	mlx->map[mlx->pos_i][mlx->pos_j] = 'P';
	if (direction == UP)
		mlx->map[mlx->pos_i + 1][mlx->pos_j] = '0';
	else if (direction == DOWN)
		mlx->map[mlx->pos_i - 1][mlx->pos_j] = '0';
	else if (direction == LEFT)
		mlx->map[mlx->pos_i][mlx->pos_j + 1] = '0';
	else if (direction == RIGHT)
		mlx->map[mlx->pos_i][mlx->pos_j - 1] = '0';
}

void	manage_direction(int direction, t_mlx_data *mlx)
{
	if (direction == UP)
		mlx->pos_i++;
	else if (direction == DOWN)
		mlx->pos_i--;
	else if (direction == LEFT)
		mlx->pos_j++;
	else if (direction == RIGHT)
		mlx->pos_j--;
}
