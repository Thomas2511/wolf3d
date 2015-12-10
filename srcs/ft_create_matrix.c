/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:08:59 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/14 15:38:08 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"wolf3d.h"

static int		ft_maxlen(t_mylist *save)
{
	int			maxlen;

	maxlen = 0;
	while (save)
	{
		if (ft_size_of(save->content) > maxlen)
			maxlen = ft_size_of(save->content);
		save = save->next;
	}
	return (maxlen);
}

static int		ft_mylist_size(t_mylist *begin_list)
{
	int			i;
	t_mylist	*list;

	i = 0;
	list = NULL;
	list = begin_list;
	if (list != NULL)
	{
		i = 1;
		while (list->next != NULL)
		{
			list = list->next;
			i++;
		}
	}
	return (i);
}

static t_cd		***ft_init_matrix(int length, int width)
{
	int			y;
	int			x;
	t_cd		***matrix;

	if ((matrix = (t_cd***)malloc(sizeof(t_cd**) * (length + 3))) == NULL)
		return (NULL);
	y = 0;
	while (y < length + 2)
	{
		if ((matrix[y] = (t_cd**)malloc(sizeof(t_cd*) * (width + 3))) == NULL)
			return (NULL);
		x = 0;
		while (x < width + 2)
		{
			if ((matrix[y][x] = (t_cd*)malloc(sizeof(t_cd))) == NULL)
				return (NULL);
			matrix[y][x]->is_wall = -1;
			x++;
		}
		matrix[y][x] = NULL;
		y++;
	}
	matrix[y] = NULL;
	return (matrix);
}

t_cd			***ft_create_matrix(t_mylist *save)
{
	int			x;
	int			y;
	t_cd		***matrix;

	matrix = ft_init_matrix(ft_mylist_size(save), ft_maxlen(save));
	y = 1;
	while (save)
	{
		x = 1;
		while (((char **)(save->content))[x - 1])
		{
			matrix[y][x]->is_wall = ft_atoi(((char **)(save->content))[x - 1]);
			x++;
		}
		save = save->next;
		y++;
	}
	return (matrix);
}
