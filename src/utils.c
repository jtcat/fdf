/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2023/04/21 17:28:35 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	t_ivec3_init(t_ivec3 *vector)
{
	vector->x = 0;
	vector->y = 0;
	vector->z = 0;
}

void	t_ivec2_init(t_ivec2 *vector)
{
	vector->x = 0;
	vector->y = 0;
}

t_ivec3 vec3_sum(t_ivec3 v1, t_ivec3 v2)
{
	return ((t_ivec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

argb	uni_rgb(int r, int g, int b)
{
	return (b | (g << 8) | (r << 16));
}
