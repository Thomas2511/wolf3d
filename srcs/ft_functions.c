/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:53:07 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 16:40:37 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"wolf3d.h"

float			ft_rad(float rad)
{
	if (rad > 2 * M_PI)
		return (ft_rad(rad - 2 * M_PI));
	if (rad < 0)
		return (ft_rad(2 * M_PI + rad));
	return (rad);
}

float			ft_abs(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int				ft_size_of(char **split)
{
	int			i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int				ft_save_size(t_mylist *save)
{
	int			i;
	int			max_line;

	max_line = 0;
	while (save)
	{
		i = 0;
		while (((char*)save->content)[i])
			i++;
		if (max_line < i)
			max_line = i;
		save = save->next;
	}
	return (max_line);
}

void			ft_lpbptr(t_mylist **alst, char **content, size_t content_size)
{
	t_mylist	*list;

	list = NULL;
	if (*alst == NULL)
	{
		list = (t_mylist*)malloc(sizeof(t_mylist));
		list->content = content;
		list->content_size = content_size;
		*alst = list;
	}
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = (t_mylist*)malloc(sizeof(t_mylist));
		list->next->content = content;
		list->next->content_size = content_size;
	}
}
