/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:42:17 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/15 13:12:34 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_rcontext *cont, t_ivec2 start, t_ivec2 end, i_rgb color)
{
	int	dx, sx, dy, sy, error, e2;

	dx = abs(end.x - start.x);
    sx = (start.x < end.x) * 2 - 1; 
    dy = -abs(end.y - start.y);
    sy = (start.y < end.y) * 2 - 1;
    error = dx + dy;
    while (1)
	{
        plot(start.x, start.y)
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
