/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:15:49 by aalmela-          #+#    #+#             */
/*   Updated: 2022/04/28 15:32:30 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "images/wall.xpm"
# define PLAYER "images/player.xpm"
# define CONTENT "images/content.xpm"
# define EXIT "images/exit.xpm"
# define SPACE "images/space.xpm"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <errno.h>

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	int		line_length;
	void	*wall;
	void	*player;
	void	*space;
	void	*collect;
	void	*exit;
}	t_img;

typedef struct s_map
{
	int		heigth;
	int		width;
	int		fd;
	int		exit;
	int		walls;
	int		content;
	int		player;
	char	**map;
	char	*path;
	char	*c_line;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_map;

void	move_up(void);
void	move_down(void);
void	move_left(void);
void	move_right(void);
void	key_close(t_map *m);
int		key_hook(int keycode, t_map *m);
t_map	*load_map(char *path);
t_map	*validations(t_map *m);
int		validate_map(t_map *map);
int		validate_line(char *line, char *chain);
int		validate_extension(char *path);
int		validate_content(t_map *m_map);
int		validate_walls(t_map *map);
int		save_map(t_map *m_map);
void	get_map_line(t_map *m);
void	create_screen(t_map *map);
void	init_structure(t_map *m);
void	search_chars(t_map *m);
char	**create_structure(t_map *m);
void	create_images(t_map *m);
int		load_images(t_map *m);
void	print_map(t_map *m);
void	add_picture(t_map *m, int i, int j);
int		clean_memory(t_map *m);
int		destroy_win(t_map *m);
int		destroy_images(t_map *m);
#endif
