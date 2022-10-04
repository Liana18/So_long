/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:46:15 by lter-zak          #+#    #+#             */
/*   Updated: 2022/09/21 20:09:52 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"

# define UP			126	
# define DOWN		125
# define LEFT		123	
# define RIGHT		124	
# define W			13
# define S			1
# define A			0
# define D			2
# define ESC		53
# define IMG_SZ		60

//---------------------------------------------------------------------------//

typedef struct s_player_pos	t_player_pos;

struct s_player_pos
{
	size_t	pos_i;
	size_t	pos_j;
};

//---------------------------------------------------------------------------//

typedef struct s_map_conten	t_map_conten;

struct s_map_conten
{
	int				count_exit;
	int				count_collec;
	int				count_player;
	int				count_enemy;
	size_t			i;
	size_t			j;
};

//---------------------------------------------------------------------------//
typedef struct s_mlx_data	t_mlx_data;

struct s_mlx_data
{	
	void			*mlx;
	void			*win;
	void			*w_1;
	void			*p_p;
	void			*c_c;
	void			*fon_0;
	void			*exit;
	void			*enemy_y;
	void			*enemy_z;
	int				sz_i;
	int				sz_j;
	int				pos_i;
	int				pos_j;
	char			**map;
	int				move_count;
	int				count_collec;
	size_t			line_count;
	size_t			line_len;
	t_map_conten	map_cont;
};

//---------------------------------------------------------------------------//

int				check_ber(char *str);
void			ft_putnbr(int nb);
void			free_map(char **map);
char			*ft_itoa(int n);
void			print_error(char *str);
void			img_flip(int kay, t_mlx_data mlx);
int				print_steps(t_mlx_data *mlx);
void			move_hook(t_mlx_data *mlx);
void			xpm_to_img(t_mlx_data *mlx);
void			send_to_draw(t_mlx_data *mlx);
void			check_arguments(int nb, char *str);
void			manage_move(int direction, t_mlx_data *mlx);
//void			send_to_draw(t_mlx_data *mlx, t_read_data *map);
void			manage_direction(int direction, t_mlx_data *mlx);
void			count_collect(t_mlx_data *map);
t_mlx_data		map_creator(char *path);
t_map_conten	*es_kanem(void);
void			ft_cikl(t_mlx_data *map, t_map_conten *count);
#endif
