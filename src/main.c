/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:58:45 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/12 09:29:01 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_node(t_tet *node)
{
	t_tet	*tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

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

t_tet		*create_node(int letter)
{
	t_tet	*node;

	node = malloc(sizeof(t_tet));
	node->next = NULL;
	node->letter = letter;
	return (node);
}

int			main(int ac, char **av)
{
	int		fd;
	t_tet	*node;
	t_map	*map;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		exit(1);
	}
	if (read(fd, av[0], 0) < 0 || fd < 0)
		f_error();
	node = create_node('A');
	f_read(fd, node);
	map = malloc_t_map(min_map(node));
	map->node = node;
	g_quan = size_list(node);
	if (g_quan > 26)
		f_error();
	algoritm(map, 0, 0, 0);
	print_map(map);
	free_map(map->map, map->size);
	free(map);
	return (1);
}
