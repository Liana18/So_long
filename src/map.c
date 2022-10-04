/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:51:16 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 20:09:02 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_odd_cep(t_mlx_data *map)
{
	t_map_conten	count;

	count.i = 1;
	count.j = 0;
	count.count_collec = 0;
	count.count_exit = 0;
	count.count_player = 0;
	count.count_enemy = 0;
	ft_cikl(map, &count);
	if (count.count_collec == 0 || count.count_exit == 0
		|| count.count_player == 0 || count.count_player > 1
		|| count.count_enemy == 0)
		print_error("                Error\n\n           C,E or P is missing");
}

//---------------------------------------------------------------------------//

int	check_odd_chars(t_mlx_data *map)
{
	size_t				i;
	size_t				j;

	j = 0;
	i = 0;
	while (i < map->line_count - 1)
	{
		j = 0;
		while (j < map->line_len)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' &&
				map->map[i][j] != 'E' && map->map[i][j] != 'C' &&
				map->map[i][j] != 'P' && map->map[i][j] != 'Y' &&
				map->map[i][j] != 'Z')
				print_error("              Error\n\n     Wrong character inside");
			j++;
		}
		i++;
	}
	return (0);
}

//---------------------------------------------------------------------------//

void	check_walls(t_mlx_data *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (j < map->line_len)
	{
		if (map->map[0][j] != '1' || map->map[map->line_count - 1][j] != '1')
			print_error("                Error\n\n           Wrong map row!= 1");
		j++;
	}
	while (i < map->line_count - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->line_len - 1] != '1')
		{	
			print_error("                Error\n\n            Wrong map col!= 1");
		}
		i++;
	}
}

//---------------------------------------------------------------------------//

void	fill_map(t_mlx_data *map, char *path)
{
	size_t	i;
	int		fd;

	i = -1;
	fd = open(path, O_RDONLY);
	map->map = malloc(sizeof(char *) * map->line_count + 1);
	if (!map->map)
		return ;
	map->map[map->line_count] = NULL;
	while (++i < map->line_count)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
			break ;
		if (ft_strlen(map->map[i]) != map->line_len + 1)
			print_error("               Error\n\n             Wrong map");
	}
	map->map[++i] = 0;
}

//---------------------------------------------------------------------------//

t_mlx_data	map_creator(char *path)
{
	t_mlx_data	map;
	int			fd;
	char		*str;

	str = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("                Error\n\n     Cant open .ber file");
	map.line_count = 0;
	map.line_len = 0;
	str = get_next_line(fd);
	map.line_len = ft_strlen(str) - 1;
	while (str)
	{
		map.line_count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	fill_map(&map, path);
	check_walls(&map);
	check_odd_chars(&map);
	check_odd_cep(&map);
	return (map);
}
