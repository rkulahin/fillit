/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:16:18 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/08 20:20:56 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../GNL/get_next_line.h"
# include "../libft/libft.h"

typedef struct		s_tet
{
	int				coords[4][2];
	char			letter;
	struct s_tet	*next;
}					t_tet;

typedef struct		s_map
{
	char			**map;
	t_tet			*node;
	int				size;
}					t_map;

int		g_quan;

void				f_error(void);
void				f_read(int fd, t_tet *node);
void				f_read2(char **arr, t_tet *node);
void				count_dh(char **arr);
int					count_touch(char **arr);
t_tet				*find_tet(t_tet *node);
void				find_coord(char **arr, int coords[4][2]);
void				free_arr(char **map, int size);
int					min_map(t_tet *node);
void				add_tet(t_map *map, int x, int y, int index);
int					put_tet(t_map *map, int x, int y, int index);
t_tet				*index_tet(t_tet *tmp, int index);
int					algoritm(t_map *map, int x, int y, int num_tet);
int					algoritm2(t_map *map, int x, int y, int num_tet);
void				free_map(char **map, int size);
char				**malloc_map(int size);
void				dell_tet(int index, t_map *map);
t_map				*malloc_t_map(int size);
void				print_map(t_map *map);

#endif
