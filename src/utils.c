/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2023/05/07 12:58:03 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dvec3	dvec3_sum(t_dvec3 v1, t_dvec3 v2)
{
	return ((t_dvec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_argb	uni_rgb(int r, int g, int b)
{
	return (b | (g << 8) | (r << 16));
}

double	calc_scale(t_ivec3 dim)
{
	double	test;

	test = 1200.f / (double)(sqrt(
				dim.x * dim.x + dim.y * dim.y + dim.z * dim.z));
	return (test);
}

int	in_range(int lower, int upper, int numb)
{
	return (numb >= lower && numb <= upper);
}

t_dvec3	mat3_dvec3_prod(const t_mat3 mat, t_dvec3 vec)
{
	t_dvec3	new_vec;

	new_vec.x = mat[0] * vec.x + mat[1] * vec.y + mat[2] * vec.z;
	new_vec.y = mat[3] * vec.x + mat[4] * vec.y + mat[5] * vec.z;
	new_vec.z = mat[6] * vec.x + mat[7] * vec.y + mat[8] * vec.z;
	return ((t_dvec3){round(new_vec.x), round(new_vec.y), 0});
}
