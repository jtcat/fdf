/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:11:27 by joaoteix          #+#    #+#             */
/*   Updated: 2023/05/02 18:44:52 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	key_handler(int keycode, void *params)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(params);
	return (1);
}

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
	const double a = -35.264f;
	const double b = -45;
	const t_mat3	rot_mat = {
		cos(b), 0, -sin(b),
		sin(a)*sin(b), cos(a), cos(b)*sin(a),
		cos(a)*sin(b), -sin(a), cos(a)*cos(b)};
	t_ivec2			p;

	p = (t_ivec2){-1, -1};
	while (++p.x < ctx->map_dim.x)
	{
		p.y = -1;
		while (++p.y < ctx->map_dim.y)
		{
			ctx->proj_map[p.x][p.y] = mat3_vec3_prod(rot_mat,
					(t_ivec3){(p.x - ctx->map_dim.x / 2) * ctx->scale,
					ctx->raw_map[p.y][p.x] * ctx->scale,
					(p.y - ctx->map_dim.y / 2) * ctx->scale});
			ctx->proj_map[p.x][p.y] = vec3_sum(ctx->proj_map[p.x][p.y],
				(t_ivec3){ctx->win_dim.x / 2, ctx->win_dim.y / 2, 0});
		}
	}
}

void	init_proj_map(t_ivec3 ***map, t_ivec3 dim)
{
	*map = malloc(sizeof(t_ivec3 *) * dim.x);
	while (dim.x-- > 0)
		(*map)[dim.x] = malloc(sizeof(t_ivec3) * dim.y);
}

void	create_window(t_rcontext *ctx)
{
	mlx_get_screen_size(ctx->mlx_ptr, &ctx->win_dim.x, &ctx->win_dim.y);
	ctx->win_dim.x -= 300;
	ctx->win_dim.y -= 200;
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr,
			ctx->win_dim.x,
			ctx->win_dim.y, WIN_TITLE);
	ctx->img = mlx_new_image(ctx->mlx_ptr, ctx->win_dim.x, ctx->win_dim.y);
	ctx->img_addr = mlx_get_data_addr(ctx->img,
			&ctx->color_depth, &ctx->line_len, &ctx->endian);
	ctx->scale = calc_scale(ctx->map_dim);
	init_proj_map(&ctx->proj_map, ctx->map_dim);
	project_map(ctx);
	draw_image(ctx);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, ctx->img, 0, 0);
}

void	destroy_context(t_rcontext *ctx)
{
	mlx_destroy_image(ctx->mlx_ptr, ctx->img);
	mlx_destroy_window(ctx->mlx_ptr, ctx->win_ptr);
	mlx_destroy_display(ctx->mlx_ptr);
	while (ctx->map_dim.y-- > 0)
		free(ctx->raw_map[ctx->map_dim.y]);
	free(ctx->raw_map);
	while (ctx->map_dim.x-- > 0)
		free(ctx->proj_map[ctx->map_dim.x]);
	free(ctx->proj_map);
	free(ctx->mlx_ptr);
	free(ctx);
}

int	render_main(int **map, t_ivec3 dim)
{
	t_rcontext	*ctx;

	ctx = malloc(sizeof(t_rcontext));
	ctx->mlx_ptr = mlx_init();
	ctx->raw_map = map;
	ctx->map_dim = dim;
	ctx->line_color = uni_rgb(255, 255, 255);
	create_window(ctx);
	mlx_key_hook(ctx->win_ptr, &key_handler, ctx->mlx_ptr);
	mlx_hook(ctx->win_ptr, DESTROY_NOTIFY, 0, &mlx_loop_end, ctx->mlx_ptr);
	mlx_loop(ctx->mlx_ptr);
	destroy_context(ctx);
	return (1);
}
