/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:11:27 by joaoteix          #+#    #+#             */
/*   Updated: 2023/05/07 12:58:59 by joaoteix         ###   ########.fr       */
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

void	init_proj_map(t_dvec3 ***map, t_ivec3 dim)
{
	*map = malloc(sizeof(t_dvec3 *) * dim.x);
	while (dim.x-- > 0)
		(*map)[dim.x] = malloc(sizeof(t_dvec3) * dim.y);
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
