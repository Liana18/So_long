/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:28:09 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 17:48:52 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_the_step(int direction, t_mlx_data *mlx)
{
	if (mlx->map[mlx->pos_i][mlx->pos_j]
		== 'E' && mlx->count_collec == 0)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx->move_count++;
		exit(0);
	}
	else if (mlx->map[mlx->pos_i][mlx->pos_j] == '1'
	|| mlx->map[mlx->pos_i][mlx->pos_j] == 'E')
		manage_direction(direction, mlx);
	else if (mlx->map[mlx->pos_i][mlx->pos_j] == 'Y'
	|| mlx->map[mlx->pos_i][mlx->pos_j] == 'Z')
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		print_error("\n             Game over \n");
	}
	else
	{
		if (mlx->map[mlx->pos_i][mlx->pos_j] == 'C')
			mlx->count_collec--;
		mlx->move_count++;
		manage_move(direction, mlx);
		mlx_clear_window(mlx->mlx, mlx->win);
		send_to_draw(mlx);
	}
}

//---------------------------------------------------------------------------//

void	key_hook(int key, t_mlx_data *mlx)
{
	if (key == W || key == UP)
	{
		mlx->pos_i--;
		do_the_step(UP, mlx);
	}
	if (key == S || key == DOWN)
	{
		mlx->pos_i++;
		do_the_step(DOWN, mlx);
	}
	if (key == A || key == LEFT)
	{
		mlx->p_p = mlx_xpm_file_to_image(mlx->mlx, "./img/player_f.xpm",
				&mlx->sz_i, &mlx->sz_j);
		mlx->pos_j--;
		do_the_step(LEFT, mlx);
	}
	if (key == D || key == RIGHT)
	{
		mlx->p_p = mlx_xpm_file_to_image(mlx->mlx, "./img/player_p.xpm",
				&mlx->sz_i, &mlx->sz_j);
		mlx->pos_j++;
		do_the_step(RIGHT, mlx);
	}
}

//---------------------------------------------------------------------------//

int	exit_game(t_mlx_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	print_error("\n             ESK Game \n");
	return (0);
}

//---------------------------------------------------------------------------//

int	key_check(int key, t_mlx_data *mlx)
{
	if (key == ESC)
		exit_game(mlx);
	else
	{
		key_hook(key, mlx);
		write(1, "move count = \n", 13);
		ft_putnbr(mlx->move_count);
		write(1, "\n", 1);
		print_steps(mlx);
	}
	return (0);
}

//---------------------------------------------------------------------------//

void	move_hook(t_mlx_data	*mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_check, mlx);
}
