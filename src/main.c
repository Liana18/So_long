/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:29:08 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 19:30:54 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int nb, char *str[])
{
	t_mlx_data		mlx;

	check_arguments(nb, str[1]);
	mlx = map_creator(str[1]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.line_len * 60,
			mlx.line_count * 60, "Alice In Wonderland");
	xpm_to_img(&mlx);
	count_collect(&mlx);
	send_to_draw(&mlx);
	move_hook(&mlx);
	mlx_loop(mlx.mlx);
}
