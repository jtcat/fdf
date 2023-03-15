/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:41:00 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/15 15:24:25 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 600
# define WIN_TITLE "FdF"

# define DESTROY_NOTIFY 17
# define KEY_ESC 65307

typedef int	int_rgb;
typedef int[9] mat3;

typedef struct s_ivec3
{
	int	x;
	int	y;
	int	z;
}	t_ivec3;

typedef struct s_ivec2
{
	int x;
	int y;
}	t_ivec2;

typedef struct s_rcontext
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_ivec3	win_dim;
	int		**map;
	t_ivec3	map_dim;
}	t_rcontext;

int render_main(int **map, t_ivec3 dim);

int_rgb	uni_rgb(int r, int g, int b);

#endif
