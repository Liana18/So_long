/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:45 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 16:32:38 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collect(t_mlx_data *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	mlx->move_count = 0;
	mlx->pos_i = 0;
	mlx->pos_j = 0;
	while (i < mlx->line_count)
	{
		j = 0;
		while (j < mlx->line_len)
		{
			if (mlx->map[i][j] == 'C')
				mlx->count_collec++;
			if (mlx->map[i][j] == 'P')
			{
				mlx->pos_i = i;
				mlx->pos_j = j;
			}
			j++;
		}
		i++;
	}
}
