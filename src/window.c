/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:11:27 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/15 15:33:14 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handler(int keycode, void *params)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(params);
	return 1;
}

void	render_image(t_rcontext *context, void *img)
{
	(void)context;
	(void)img;
}

int	loop_handler(t_rcontext *context)
{
	void	*img;

	img = mlx_new_image(context->mlx_ptr, context->win_dim.x, context->win_dim.y);
	render_image(context, img);
	mlx_put_image_to_window(context->mlx_ptr, context->win_ptr, img, 0, 0);
	mlx_destroy_image(context->mlx_ptr, img);
	return (1);
}

void	*create_window(void *mlx_ptr)
{
	void	*win_ptr;
	t_ivec3	screen_size;

	mlx_get_screen_size(mlx_ptr, &screen_size.x, &screen_size.y);
	win_ptr = mlx_new_window(mlx_ptr, screen_size.x - 300, screen_size.y - 200, WIN_TITLE);
	return (win_ptr);
}

int	render_main(int **map, t_ivec3 dim)
{
	t_rcontext	*context;

	context = malloc(sizeof(t_rcontext));
	context->mlx_ptr = mlx_init();
	context->win_ptr = create_window(context->mlx_ptr);
	context->map = map;
	context->map_dim = dim;
	mlx_key_hook(context->win_ptr, &key_handler, context->mlx_ptr);
	mlx_hook(context->win_ptr, DESTROY_NOTIFY, 0, &mlx_loop_end, context->mlx_ptr);
	mlx_loop_hook(context->win_ptr, &loop_handler, NULL);
	mlx_loop(context->mlx_ptr);
	mlx_destroy_window(context->mlx_ptr, context->win_ptr);
	mlx_destroy_display(context->mlx_ptr);
	free(context->mlx_ptr);
	free(context);
	return (1);
}
