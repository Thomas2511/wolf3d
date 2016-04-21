/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:14:29 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 16:33:03 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_player				*ft_place_player(t_cd ***matrix)
{
	t_player			*player;
	int					x;
	int					y;

	if ((player = (t_player*)malloc(sizeof(t_player))) == NULL)
		return (NULL);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x]->is_wall == 0)
			{
				player->y = y * BLOCK + (BLOCK / 2);
				player->x = x * BLOCK + (BLOCK / 2);
				player->pov = 0;
				return (player);
			}
			x++;
		}
		y++;
	}
	return (player);
}
