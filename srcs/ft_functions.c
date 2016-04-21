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

#include "wolf3d.h"

int				ft_size_of(char **split)
{
	int			i;

	i = 0;
	while (split && split[i])
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

t_mylist		*ft_listnext(char **content, size_t content_size)
{
	t_mylist	*list;

	if ((list = (t_mylist *)malloc(sizeof(t_mylist))) == NULL)
		return (NULL);
	list->content = content;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}

void			ft_lpbptr(t_mylist **alst, char **content, size_t content_size)
{
	t_mylist	*list;

	list = NULL;
	if (*alst == NULL)
		*alst = ft_listnext(content, content_size);
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = ft_listnext(content, content_size);
	}
}
