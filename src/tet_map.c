/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:46:33 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/11 17:11:16 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*math_custom(int arr[2], int coords[4][2], int i)
{
	int *cord;

	arr[0] = arr[0] + (coords[i][0] - coords[i - 1][0]);
	arr[1] = arr[1] + (coords[i][1] - coords[i - 1][1]);
	cord = arr;
	return (cord);
}

t_tet			*index_tet(t_tet *tmp, int index)
{
	while (tmp->next)
	{
		if (tmp->letter == 'A' + index)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void			add_tet(t_map *map, int x, int y, int index)
{
	int		i;
	t_tet	*tmp;
	char	**arr;
	int		*c;

	c = (int *)malloc(sizeof(int) * 2);
	c[0] = x;
	c[1] = y;
	tmp = map->node;
	arr = map->map;
	i = 0;
	tmp = index_tet(tmp, index);
	while (i < 4)
	{
		if (i > 0)
			c = math_custom(c, tmp->coords, i);
		arr[c[0]][c[1]] = tmp->letter;
		i++;
	}
	free(c);
}

int				custom_pt(int c[2], int size, char **arr)
{
	if ((c[0] < 0 || c[0] >= size) || (c[1] < 0 || c[1] >= size))
	{
		free(c);
		return (0);
	}
	else if (arr[c[0]][c[1]] != 0)
	{
		free(c);
		return (0);
	}
	return (1);
}

int				put_tet(t_map *map, int y, int x, int index)
{
	int		i;
	long	size;
	t_tet	*tmp;
	char	**arr;
	int		*c;

	c = (int *)malloc(sizeof(int) * 2);
	c[0] = x;
	c[1] = y;
	tmp = map->node;
	size = map->size;
	arr = map->map;
	i = -1;
	tmp = index_tet(tmp, index);
	while (++i < 4)
	{
		if (i > 0)
			c = math_custom(c, tmp->coords, i);
		if (custom_pt(c, size, arr) == 0)
			return (0);
	}
	add_tet(map, x, y, index);
	free(c);
	return (1);
}
