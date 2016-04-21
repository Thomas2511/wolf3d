/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 18:59:06 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 17:45:19 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					ft_get_pixel(t_img *img, int x, int y)
{
	int				max_idx;
	int				index;
	int				i;
	int				color;

	color = 0;
	max_idx = img->height * img->size_line + img->width * (img->bpp / 8);
	index = y * img->size_line + x * (img->bpp / 8);
	i = 0;
	while (i < img->bpp / 8 && (index + i) < max_idx)
	{
		((char*)&color)[i] = img->data[index + i];
		i++;
	}
	return (color);
}

t_img				*ft_img_init(void *mlx_ptr, int width, int height)
{
	t_img			*new;

	if ((new = (t_img *)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	new->mlx_img = mlx_new_image(mlx_ptr, width, height);
	new->height = height;
	new->width = width;
	new->data = mlx_get_data_addr(new->mlx_img, &new->bpp, &new->size_line,
			&new->endian);
	return (new);
}

t_img				*ft_get_img(void *mlx_ptr, char *file_name)
{
	t_img			*new;

	if ((new = (t_img *)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	new->mlx_img = mlx_xpm_file_to_image(mlx_ptr, file_name, &new->width,
			&new->height);
	new->data = mlx_get_data_addr(new->mlx_img, &new->bpp, &new->size_line,
			&new->endian);
	return (new);
}

void				ft_pixel_put(t_img *img, int x, int y, int color)
{
	int				max_idx;
	int				index;
	int				i;

	max_idx = img->height * img->size_line + img->width * (img->bpp / 8);
	index = y * img->size_line + x * (img->bpp / 8);
	i = 0;
	while (i < img->bpp / 8 && (index + i) < max_idx)
	{
		img->data[index + i] = ((char*)&color)[i];
		i++;
	}
}
