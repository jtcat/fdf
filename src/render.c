/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:11:27 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/03 19:14:16 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *params)
{
	if (keycode == 27)

}

int	render_main(int **map, t_vec3 dim)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_key_hook(win_ptr, &key_hook, (void *)NULL);
	mlx_loop_hook(win_ptr, &loop, (void *)NULL);
	mlx_loop(mlx_ptr);
}
