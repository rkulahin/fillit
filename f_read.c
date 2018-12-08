/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:18:20 by rkulahin          #+#    #+#             */
/*   Updated: 2018/12/08 20:19:36 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		f_read2(char **arr, t_tet *node)
{
	count_dh(arr);
	find_coord(arr, find_tet(node)->coords);
	free_arr(arr, 5);
}

void		f_read(int fd, t_tet *node)
{
	int		i;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 5);
	i = 0;
	while ((get_next_line(fd, &arr[i])) == 1)
	{
		if (i == 4)
		{
			if (arr[i][0] == '\0')
			{
				f_read2(arr, node);
				arr = (char **)malloc(sizeof(char *) * 5);
				i = 0;
			}
			else
				f_error();
		}
		else if (ft_strlen(arr[i++]) != 4)
			f_error();
	}
	if (arr[0] == NULL)
		f_error();
	f_read2(arr, node);
}
