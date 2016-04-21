/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:20:09 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/14 15:23:25 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(int argc, char **argv)
{
	int			fd;
	t_mylist	*save;
	char		*line;
	t_cd		***matrix;
	char		**split;

	save = NULL;
	if (argc != 2)
		return (ft_putendl_fd("usage: ./wolf3D map", 2));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		perror(argv[1]);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		ft_lpbptr(&save, split, ft_size_of(split));
		free(line);
	}
	if (close(fd))
		perror(argv[1]);
	if (save == NULL)
		return (ft_putendl_fd("please specify a non-empty map", 2));
	matrix = ft_create_matrix(save);
	ft_wolf3d(matrix);
	return (0);
}
