/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 18:25:02 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 19:21:47 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"wolf3d.h"

int					ft_can_move(t_env *env, const float x, const float y)
{
	if (env->matrix[(int)((env->player->y) / BLOCK)]
				[(int)((env->player->x + x) / BLOCK)]->is_wall == 0)
		env->player->x += x;
	if (env->matrix[(int)((env->player->y - y) / BLOCK)]
				[(int)((env->player->x) / BLOCK)]->is_wall == 0)
		env->player->y -= y;
	return (1);
}
