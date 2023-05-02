/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2023/05/02 19:10:50 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ivec3	vec3_sum(t_ivec3 v1, t_ivec3 v2)
{
	return ((t_ivec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_argb	uni_rgb(int r, int g, int b)
{
	return (b | (g << 8) | (r << 16));
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

#include <stdio.h>

int	calc_scale(t_ivec3 dim)
{
	int	scale;
	double	test;

	scale = (dim.x * dim.y * dim.z);
	test = (80000.f / (double)(dim.x * dim.y * dim.z));
	printf("s: %f\n", test);
	return (scale);
}
