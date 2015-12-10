/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 12:04:18 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 19:29:45 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"wolf3D.h"

static void			draw_pixel(t_env *env, int x, float rad, t_cd ***matrix)
{
	float			h;
	int				y;
	int				offset;
	static t_img	*wall = NULL;

	if (wall == NULL)
		wall = ft_get_img(env->mlx, "walltexture.xpm");
	y = 0;
	h = (BLOCK * ZOOM) / ft_raycast(matrix, env->player, rad, &offset);
	while (y < W_SIZE_Y)
	{
		if (y > (W_SIZE_Y / 2) - (h / 2) && y < (W_SIZE_Y / 2) + (h / 2))
			ft_pixel_put(env->img, x, y, ft_get_pixel(wall, offset,
						(int)((y - ((W_SIZE_Y / 2) - (h / 2)))
									/ (h / wall->height))));
		else if (y > W_SIZE_Y / 2)
			ft_pixel_put(env->img, x, y, 0xFFFF11);
		else
			ft_pixel_put(env->img, x, y, 0x11FFFF);
		y++;
	}
}

static void			draw_matrix(t_cd ***matrix, t_env *env)
{
	int				x;
	float			rad;
	float			inc;

	x = 0;
	rad = ft_rad(env->player->pov + RAD(FOV / 2));
	inc = ft_rad(RAD(FOV / W_SIZE_X));
	while (x < W_SIZE_X)
	{
		draw_pixel(env, x, rad, matrix);
		rad = ft_rad(rad - inc);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->mlx_img, 0, 0);
}

static int			key_hook(int keycode, t_env *env)
{
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == DOWN_ARROW)
		ft_can_move(env, cos(env->player->pov) * -50,
							sin(env->player->pov) * -50);
	if (keycode == UP_ARROW)
		ft_can_move(env, cos(env->player->pov) * 50,
							sin(env->player->pov) * 50);
	if (keycode == RIGHT_ARROW)
		env->player->pov -= 0.1;
	if (keycode == LEFT_ARROW)
		env->player->pov += 0.1;
	draw_matrix(env->matrix, env);
	return (0);
}

static int			expose_hook(t_env *env)
{
	draw_matrix(env->matrix, env);
	return (0);
}

void				ft_wolf3d(t_cd ***matrix)
{
	t_env			env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, W_SIZE_X, W_SIZE_Y, "Wolf3D");
	env.img = ft_img_init(env.mlx, W_SIZE_X, W_SIZE_Y);
	env.matrix = matrix;
	env.player = ft_place_player(matrix);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_loop(env.mlx);
}
