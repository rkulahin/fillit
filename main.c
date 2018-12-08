/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:58:45 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/08 20:21:08 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int			min_map(t_tet *node)
{
	int		i;
	int		j;
	t_tet	*tmp;

	i = 0;
	j = 2;
	tmp = node;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	i = i * 4;
	while (j < i)
	{
		if (j * j >= i)
			return (j);
		j++;
	}
	return (0);
}

void		f_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

int			size_list(t_tet *node)
{
	int		i;

	i = 0;
	while (node->next)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int			main(int ac, char **av)
{
	int		fd;
	t_tet	*node;
	t_map	*map;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		exit(1);
	}
	fd = open("test/test.fillit", O_RDONLY);
	node = malloc(sizeof(t_tet));
	node->next = NULL;
	node->letter = 'A';
	f_read(fd, node);
	map = malloc_t_map(min_map(node));
	map->node = node;
	g_quan = size_list(node);
	if (g_quan > 26)
		f_error();
	algoritm(map, 0, 0, 0);
	print_map(map);
	return (1);
}
