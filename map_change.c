/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:13:33 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/08 19:56:57 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	free_arr(char **map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(map[i]);
	free(map);
}

void	free_map(char **map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(map[i]);
	free(map);
}

char	**malloc_map(int size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc(sizeof(char *) * size)))
		f_error();
	i = 0;
	while (i < size)
	{
		map[i] = ft_strnew(size);
		i++;
	}
	return (map);
}

t_map	*malloc_t_map(int size)
{
	t_map	*map;
	int		i;

	map = (t_map*)malloc(sizeof(t_map));
	map->size = size;
	map->map = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		(map->map)[i] = ft_strnew(size);
		i++;
	}
	return (map);
}

void	print_map(t_map *map)
{
	int		i;
	int		j;
	char	**mape;

	mape = map->map;
	i = -1;
	while (++i < map->size)
	{
		j = -1;
		while (++j < map->size)
		{
			if (mape[i][j] == 0)
				write(1, ".", 1);
			else
				write(1, &mape[i][j], 1);
		}
		write(1, "\n", 1);
	}
}
