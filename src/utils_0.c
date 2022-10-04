/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:32:35 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 20:09:15 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wnb(char n)
{
	write(1, &n, 1);
}

int	check_ber(char *str)
{
	char	*str2;
	int		j;
	int		i;

	str2 = "reb.";
	j = 0;
	i = ft_strlen(str) - 1;
	while (str2[j])
	{
		if (str2[j++] != str[i])
			return (1);
		i--;
	}
	return (0);
}

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i++])
		free(map[i]);
	free(map);
}

void	ft_putnbr(int nb)
{
	long	l;

	l = nb;
	if (l < 10)
	{
		l = l + '0';
		ft_wnb(l);
		return ;
	}
	else
		ft_putnbr(l / 10);
	ft_putnbr(l % 10);
}

void	ft_cikl(t_mlx_data *map, t_map_conten *count)
{
	while (count->i < map->line_count)
	{
		count->j = 0;
		while (count->j < map->line_len)
		{
			if (map->map[count->i][count->j] == 'C')
				count->count_collec++;
			if (map->map[count->i][count->j] == 'E')
				count->count_exit++;
			if (map->map[count->i][count->j] == 'P')
				count->count_player++;
			if (map->map[count->i][count->j] == 'Y'
				|| map->map[count->i][count->j] == 'Z')
				count->count_enemy++;
			count->j++;
		}
		count->i++;
	}
}
