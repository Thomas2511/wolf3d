/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:38:39 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 17:58:09 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"wolf3d.h"

int				ft_outside_map(t_cd ***matrix, float x, float y)
{
	int			matlen;
	int			mathgt;

	matlen = 0;
	mathgt = 0;
	while (matrix[0][mathgt])
		mathgt++;
	while (matrix[matlen])
		matlen++;
	if ((int)(x / BLOCK) < mathgt && (int)(y / BLOCK) < matlen
			&& (int)(x / BLOCK) >= 0 && (int)(y / BLOCK) >= 0)
		return (0);
	return (1);
}

static float	ft_vertical_ray(t_cd ***matrix, t_player *player, float rad,
								int	*offset_y)
{
	float		x;
	float		y;
	float		xa;
	float		ya;

	x = (IS_RIGHT(rad)) ? (int)(player->x / BLOCK) * BLOCK + BLOCK
						: (int)(player->x / BLOCK) * BLOCK - 1;
	y = player->y + ((player->x - x) * tan(rad)) + IS_UP(rad);
	xa = (IS_RIGHT(rad)) ? BLOCK : -BLOCK;
	ya = (IS_UP(rad)) ? -ft_abs(BLOCK * tan(rad)) : ft_abs(BLOCK * tan(rad));
	if (ft_outside_map(matrix, x, y))
		return (-1);
	while (!matrix[(int)(y / BLOCK)][(int)(x / BLOCK)]->is_wall)
	{
		x += xa;
		y += ya;
		if (ft_outside_map(matrix, x, y))
			return (-1);
	}
	*offset_y = (int)y % BLOCK;
	return (ft_abs(ft_abs(player->x - x) / cos(rad)));
}

static float	ft_horizontal_ray(t_cd ***matrix, t_player *player, float rad,
									int *offset_x)
{
	float		x;
	float		y;
	float		xa;
	float		ya;

	y = (IS_UP(rad)) ? (int)(player->y / BLOCK) * BLOCK - 1
						: (int)(player->y / BLOCK) * BLOCK + BLOCK;
	x = player->x + (player->y - y) / tan(rad);
	ya = (IS_DOWN(rad)) ? BLOCK : -BLOCK;
	xa = (IS_RIGHT(rad)) ? ft_abs(BLOCK / tan(rad)) : -ft_abs(BLOCK / tan(rad));
	if (ft_outside_map(matrix, x + IS_LEFT(rad), y))
		return (-1);
	while (!matrix[(int)(y / BLOCK)]
				[(int)((x + IS_LEFT(rad)) / BLOCK)]->is_wall)
	{
		x += xa;
		y += ya;
		if (ft_outside_map(matrix, x + IS_LEFT(rad), y))
			return (-1);
	}
	*offset_x = (int)x % BLOCK;
	return (ft_abs(ft_abs(player->x - x) / cos(rad)));
}

float			ft_raycast(t_cd ***matrix, t_player *player, float rad,
							int *offset)
{
	float		ver;
	float		hor;
	int			offset_x;
	int			offset_y;

	ver = -1;
	hor = -1;
	if (rad != M_PI_2 && rad != 3 * M_PI_2)
		ver = ft_vertical_ray(matrix, player, rad, &offset_y);
	if (rad != 0 && rad != M_PI && rad != 2 * M_PI)
		hor = ft_horizontal_ray(matrix, player, rad, &offset_x);
	if (ver == -1 || (hor < ver && hor != -1))
	{
		*offset = offset_x;
		return (ft_abs(hor * cos(rad - player->pov)));
	}
	else
	{
		*offset = offset_y;
		return (ft_abs(ver * cos(rad - player->pov)));
	}
}
