/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:46:22 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 19:25:57 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_steps(t_mlx_data *mlx)
{
	char	*str;

	str = ft_itoa(mlx->move_count);
	mlx_string_put(mlx->mlx, mlx->win, 20, 10, 0xFF0000, str);
	free(str);
	return (0);
}
