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

# define DOG_LEFT "./assets/dog_left.xpm"
# define DOG_RIGHT "./assets/dog.xpm"
# define TREE "./assets/bush.xpm"
# define GRASS "./assets/grass.xpm"
# define HOUSE "./assets/exit.xpm"
# define BONE "./assets/bone.xpm"

typedef struct s_player_info
{
	int y;
	int x;
}	t_player_info;

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
}	t_map;

typedef struct s_flags
{
	int		wall;
	int		back;
	int		player;
	int		collect;
	int		exit;
	int		exit2;
}	t_flags;

typedef struct s_img
{
	void	*wall;
	void	*back;
	void	*player;
	void	*collect;
	void	*exit;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		moves;
	t_img img;
	t_flags	flags;
	t_player_info player_info;
	t_map	map;
}			t_data;

void		init_game(t_data *map);
void		read_map(t_map *map, char *path);
int			map_draw(t_data *data, t_map *map, t_img *img);
void		img_draw(t_data *data, void *img, int x, int y);
void		gameplay(t_data *data);
void		move_right(t_data *data, t_img *img, int x, int y);
void		move_left(t_data *data, t_img *img, int x, int y);
void		move_up(t_data *data, t_img *img, int x, int y);
void		move_down(t_data *data, t_img *img, int x, int y);
int			close_game(t_data *data);
void		free_map(char **map);
int			check_map(t_data *data, t_flags *flags, char *path);
void		find_player(t_map *map, t_player_info *player_struct);
int			verify(int key_released, t_data *data);
void 		verify_exit(t_data *data, int x, int y);
void 		change_img(t_data *data, char *path);

#endif