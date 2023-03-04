/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:41:00 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/04 17:10:00 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 600
# define WIN_TITLE "FdF"

# define KEY_ESC 65307

typedef int	int_rgb;

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

typedef struct s_rcontext
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_vec3	win_dim;
	int		**map;
	t_vec3	map_dim;
}	t_rcontext;

int render_main(int **map, t_vec3 dim);

int_rgb	uni_rgb(int r, int g, int b);

#endif
