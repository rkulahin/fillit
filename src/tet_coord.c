/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:58:07 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/11 17:12:13 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet		*find_tet(t_tet *node)
{
	char	letter;
	t_tet	*tmp;

	tmp = node;
	if (!node->next)
	{
		tmp->next = malloc(sizeof(t_tet));
		tmp->next->next = NULL;
		return (tmp);
	}
	letter = tmp->letter;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->letter = ++letter;
	}
	tmp->next = malloc(sizeof(t_tet));
	tmp->next->next = NULL;
	return (tmp);
}

void		find_coord(char **arr, int coords[4][2])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == '#')
			{
				coords[k][1] = j;
				coords[k][0] = i;
				k++;
			}
		}
	}
}

void		dell_tet(int index, t_map *map)
{
	int		i;
	int		j;
	t_tet	*tmp;

	tmp = map->node;
	tmp = index_tet(tmp, index);
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->map[i][j] == tmp->letter)
				map->map[i][j] = 0;
			j++;
		}
		i++;
	}
}
