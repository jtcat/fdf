/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:11:27 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/22 15:38:41 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx-linux/mlx.h"

int	key_handler(int keycode, void *params)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(params);
	return 1;
}

void	draw_image(t_rcontext *context)
{
	t_ivec3	p;

	t_ivec3_init(&p);
	while (p.x++ < (context->win_dim.x - 1))
		while (p.y++ < (context->win_dim.y - 1))
		{
			draw_line(context, p.x + 1, p.y, context->line_color);
			draw_line(context, p.x, p.y + 1, context->line_color);
		}
}

void	project_map(int **og_map, t_dvec3 **rot_map, t_ivec2 size)
{
	double	*a;

	a = 35.264f;
	b = 45f;
	mat3	alpha = {1, 0, 0, 0, cos(a), sin(a), 0, -sin(a), cos(a)};
	mat3	beta = {cos(b), 0, -sin(b), 0, 1, 0, sin(b), 0, cos(b)};
	mat3	rot_mat = mat3_prod(alpha, beta);
	t_dvec3 res = mat3_vec3_prod(rot_mat, );
}

int	loop_handler(t_rcontext *ctx)
{
	render_image(ctx, ctx->img);
	mlx_put_image_to_window(ctx->mlx_ptr, ctx->win_ptr, ctx->img, 0, 0);
	return (1);
}

void	create_window(t_rcontext *ctx)
{
	int	bendian;
	int	cdepth;
	int	line_size;

	mlx_get_screen_size(ctx->mlx_ptr, &ctx->win_dim.x, &ctx->win_dim.y);
	ctx->win_ptr = mlx_new_window(ctx->mlx_ptr, 
			ctx->win_dim.x - 300, 
			ctx->win_dim.y - 200, WIN_TITLE);
	ctx->img = mlx_new_image(ctx->mlx_ptr, ctx->win_dim.x, ctx->win_dim.y);
	ctx->img_data = mlx_get_data_addr(ctx->img,
			&ctx->color_depth, &ctx->line_len, &ctx->endian);
}

int	render_main(int **map, t_ivec3 dim)
{
	t_rcontext	*context;

	context = malloc(sizeof(t_rcontext));
	context->mlx_ptr = mlx_init();
	create_window(context);
	context->map = map;
	context->map_dim = dim;
	mlx_key_hook(context->win_ptr, &key_handler, context->mlx_ptr);
	mlx_hook(context->win_ptr, DESTROY_NOTIFY, 0, &mlx_loop_end, context->mlx_ptr);
	mlx_loop_hook(context->win_ptr, &loop_handler, NULL);
	mlx_loop(context->mlx_ptr);
	mlx_destroy_window(context->mlx_ptr, context->win_ptr);
	mlx_destroy_display(context->mlx_ptr);
	mlx_destroy_image(context->mlx_ptr, context->img);
	free(context->mlx_ptr);
	free(context);
	return (1);
}
