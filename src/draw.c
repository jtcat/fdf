/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:42:17 by joaoteix          #+#    #+#             */
/*   Updated: 2023/04/21 15:37:20 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	in_range(int lower, int upper, int numb)
{
	return (numb >= lower && numb <= upper);
}

void	plot(t_rcontext *ctx, int x, int y, argb color)
{
	char	*dst;

	if (in_range(0, ctx->win_dim.x, x) && in_range(0, ctx->win_dim.y, y))
	{
		dst =  ctx->img_addr + y  * ctx->line_len + x * (ctx->color_depth / 8);
		*(unsigned int*)dst = color;
	}
}

void	draw_line(t_rcontext *ctx, t_ivec3 start, t_ivec3 end, argb color)
{
	int	dx, sx, dy, sy, error, e2;

	dx = abs(end.x - start.x);
    sx = (start.x < end.x) * 2 - 1; 
    dy = -abs(end.y - start.y);
    sy = (start.y < end.y) * 2 - 1;
    error = dx + dy;
    while (1)
	{
        plot(ctx, start.x, start.y, color);
        if (start.x == end.x && start.y == end.y)
			break ;
        e2 = 2 * error;
        if (e2 >= dy)
		{
            if (start.x == end.x)
 				break ;
			error += dy;
            start.x += sx;
		}
        if (e2 <= dx)
		{
            if (start.y == end.y)
				break ;
            error += dx;
            start.y += sy;
		}
	}
}

t_ivec3	mat3_vec3_prod(const mat3 mat, t_ivec3 vec)
{
	t_dvec3	new_vec;

	new_vec.x = mat[0] * vec.x + mat[1] * vec.y + mat[2] * vec.z;
	new_vec.y = mat[3] * vec.x + mat[4] * vec.y + mat[5] * vec.z;
	new_vec.z = mat[6] * vec.x + mat[7] * vec.y + mat[8] * vec.z;
	return (t_ivec3){round(new_vec.x), round(new_vec.y), 0};
}
