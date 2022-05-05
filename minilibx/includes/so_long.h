/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:15:49 by aalmela-          #+#    #+#             */
/*   Updated: 2022/05/05 12:43:49 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "assets/wall.xpm"
# define PLAYER "assets/player.xpm"
# define CONTENT "assets/content.xpm"
# define EXIT "assets/exit.xpm"
# define SPACE "assets/space.xpm"
# define PARAM "\nError: Wrong parameters"
# define EXTENSION "\nError: Wrong file extension"
# define FOPEN "\nError: Cant't open file"
# define MAPINVALID "\nError: Map not valid"
# define MAPINVALIDWALL "\nError: Walls not valid"
# define MAPINVALIDCONTENT "\nError: Content not valid"
# define IMAGEPLAYERNOTFOUND "\nError: PLAYER image not found"
# define IMAGECONTENTNOTFOUND "\nError: CONTENT image not found"
# define IMAGEEXITNOTFOUND "\nError: EXIT image not found"
# define IMAGESPACENOTFOUND "\nError: SPACE image not found"
# define IMAGEWALLNOTFOUND "\nError: WALL image not found"
# define LIBRARYERROR "\nError: loading library mlx"
# define TITLEAPP "So long aplication"
# define WALLDETECTED "Can't move in that direction, wall detected"
# define EXITDETECTED "Can't exit, have more content, go get it"
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
	void	*wall;
	void	*player;
	void	*space;
	void	*collect;
	void	*exit;
}	t_img;

typedef struct s_data
{
	int		heigth;
	int		width;
	int		fd;
	int		exit;
	int		walls;
	int		content;
	int		player;
	int		coordx;
	int		coordy;
	char	**map;
	char	*error;
	char	*path;
	char	*c_line;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_data;

void	init_structure(t_data *data);
int		key_hook(int keycode, t_data *data);
int		is_valid(t_data *data);
int		validate(char *path, t_data *data);
int		validate_extension(char *path);
int		validate_map_size(t_data *data);
int		validate_line(char *line, char *chain);
int		validate_walls(t_data *data);
int		validate_content(t_data *data);
int		file_exist(char *path, t_data *data);
void	put_error(char *str, t_data *data);
void	get_map_line(t_data *data);
void	search_chars(t_data *data);
int		clean_memory(t_data *data);
int		load_images(t_data *data);
void	add_picture(t_data *data, int i, int j);
void	print_map(t_data *data);
int		create_screen(t_data *data);
void	destroy_window(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move(t_data *data, int i, int j);
#endif
