/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:41:37 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/12/24 19:49:25 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
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
	int		height;
	int		width;
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

int		read_map(int fd, t_map *map, char *path);
void	save_dir(t_map *map);
int		save_fc(t_map *map);
void	save_map(t_map *map, int pos);
int		checkwalls(int x, int y, t_map *map);
void	save_tmp(t_map *map);
// int    	last_pos(t_map *map);

//utils:

void	*ft_realloc(void *ptr, int size);

#endif