/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:49:26 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/15 18:54:28 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# define ESC 65307
# define LEFT_ARROW 65361
# define UP_ARROW 65362
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define LEFT 97
# define UP 119
# define RIGHT 100
# define DOWN 115

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	void	*wall;
	void	*back;
	void	*player;
	void	*collect;
	void	*exit;
	int		wall_flag;
	int		back_flag;
	int		player_flag;
	int		collect_flag;
	int		exit_flag;
	int		exit_flag2;
	int		player_y;
	int		player_x;
	int		moves;
}			t_data;

void		init_game(t_data *map);
void		read_map(t_data *data, char *path);
int			map_draw(t_data *data);
void		img_draw(t_data *data, void *img, int x, int y);
void		gameplay(t_data *data);
void		move_right(t_data *data, int x, int y);
void		move_left(t_data *data, int x, int y);
void		move_up(t_data *data, int x, int y);
void		move_down(t_data *data, int x, int y);
int			close_game(t_data *data);
void		free_map(char **map);
int			check_map(t_data *data, char *path);
void		find_player(t_data *data);
int			verify(int key_released, t_data *data);

#endif