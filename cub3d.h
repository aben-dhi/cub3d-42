/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:41:37 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/01/07 18:08:30 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include <mlx.h>.
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_map
{
	int		rows;
	int		*columns;
	char	**file;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	char	**tmp;
	int		posx;
	int		posy;
}	t_map;

// int		read_map(int fd, t_map *map, char *path);
// void	save_dir(t_map *map);
// int		save_fc(t_map *map);
// void	save_map(t_map *map, int pos);
// int		checkwalls(int x, int y, t_map *map);
// void	save_tmp(t_map *map);
// int    	last_pos(t_map *map);

//cub3d functions:
void	read_map(int fd, t_map *map);
int		check_extension(char *file);
int		check_map_content(t_map *map);
int		check_map_player(t_map *map);
int		check_map_frame0(t_map *map);
int		check_map_frame1(t_map *map);
int		check_map_frame2(t_map *map);
int		check_textures(t_map *map);
int		check_rgb(t_map *map);
void	display_map_errors1(t_map *map);
void	display_map_errors2(t_map *map);

//utility functions:
void	*ft_realloc(void *ptr, int size);
char	*ft_datacpy(char *src, int n);
char	*skip_spaces(char *str);
int		avoid_spaces(char *str);
int		reverse_avoid_spaces(char *str);
int		check_empty_spaces(char *str);
void	display_dnl_error(char *lmap);
void	free_data(t_map *map);
void	free_tmp(char **str);

#endif