/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:42:17 by joaoteix          #+#    #+#             */
/*   Updated: 2023/05/07 13:11:59 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_image(t_rcontext *ctx)
{
	t_ivec3	p;

	p = (t_ivec3){-1, -1, -1};
	while (++p.x < ctx->map_dim.x)
	{
		p.y = -1;
		while (++p.y < ctx->map_dim.y)
		{
			if ((p.x + 1) < ctx->map_dim.x)
				draw_line(ctx, ctx->proj_map[p.x][p.y],
					ctx->proj_map[p.x + 1][p.y], ctx->line_color);
			if ((p.y + 1) < ctx->map_dim.y)
				draw_line(ctx, ctx->proj_map[p.x][p.y],
					ctx->proj_map[p.x][p.y + 1], ctx->line_color);
		}
	}
}

void	project_map(t_rcontext *ctx)
{
	const double	a = -35.264f;
	const double	b = -45;
	const t_mat3	rot_mat = {
		cos(b), 0, -sin(b),
		sin(a) * sin(b), cos(a), cos(b) * sin(a),
		cos(a) * sin(b), -sin(a), cos(a) * cos(b)};
	t_ivec2			p;

	p = (t_ivec2){-1, -1};
	while (++p.x < ctx->map_dim.x)
	{
		p.y = -1;
		while (++p.y < ctx->map_dim.y)
		{
			ctx->proj_map[p.x][p.y] = mat3_dvec3_prod(rot_mat,
					(t_dvec3){(p.x - ctx->map_dim.x / 2) * ctx->scale,
					(ctx->raw_map[p.y][p.x] - ctx->map_dim.z / 2) * ctx->scale,
					(p.y - ctx->map_dim.y / 2) * ctx->scale});
			ctx->proj_map[p.x][p.y] = dvec3_sum(ctx->proj_map[p.x][p.y],
					(t_dvec3){ctx->win_dim.x / 2, ctx->win_dim.y / 2, 0});
		}
	}
}

void	plot(t_rcontext *ctx, int x, int y, t_argb color)
{
	char	*dst;

	if (in_range(0, ctx->win_dim.x, x) && in_range(0, ctx->win_dim.y, y))
	{
		dst = ctx->img_addr + y * ctx->line_len + x * (ctx->color_depth / 8);
		*(unsigned int *)dst = color;
	}
}

int	init_draw_vars(t_ivec2 *d, t_ivec2 *s, t_dvec3 *start, t_dvec3 *end)
{
	*d = (t_ivec2){fabs(end->x - start->x), -fabs(end->y - start->y)};
	*s = (t_ivec2){(start->x < end->x) * 2 - 1, (start->y < end->y) * 2 - 1};
	return (d->x + d->y);
}

void	draw_line(t_rcontext *ctx, t_dvec3 start, t_dvec3 end, t_argb color)
{
	int		error;
	t_ivec2	d;
	t_ivec2	s;

	error = init_draw_vars(&d, &s, &start, &end);
	while (1)
	{
		plot(ctx, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		if ((error * 2) >= d.y)
		{
			if (start.x == end.x)
				break ;
			error += d.y;
			start.x += s.x;
		}
		if ((error * 2) <= d.x)
		{
			if (start.y == end.y)
				break ;
			error += d.x;
			start.y += s.y;
		}
	}
}
