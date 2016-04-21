/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:53:07 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 16:40:37 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
