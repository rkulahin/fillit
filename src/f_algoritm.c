/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_algoritm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:19:11 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/10 10:48:19 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			algoritm2(t_map *map, int x, int y, int num_tet)
{
	if (put_tet(map, x, y, num_tet))
	{
		if (algoritm(map, 0, 0, num_tet + 1))
			return (1);
		dell_tet(num_tet, map);
		if (algoritm(map, x + 1, y, num_tet))
			return (1);
		return (0);
	}
	else
	{
		if (algoritm(map, x + 1, y, num_tet))
			return (1);
		return (0);
	}
}

int			algoritm(t_map *map, int x, int y, int num_tet)
{
	if (num_tet >= g_quan)
		return (1);
	else if (x >= map->size)
	{
		if (algoritm(map, 0, y + 1, num_tet))
			return (1);
		return (0);
	}
	else if (y >= map->size)
	{
		if (num_tet == 0)
		{
			free_map(map->map, map->size);
			map->map = malloc_map(++(map->size));
			if (algoritm(map, 0, 0, 0))
				return (1);
			return (0);
		}
		else
			return (0);
	}
	else if (algoritm2(map, x, y, num_tet))
		return (1);
	return (0);
}
