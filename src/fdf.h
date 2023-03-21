/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:41:00 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/21 16:26:37 by joaoteix         ###   ########.fr       */
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
# define COLOR_DEPTH 16

# define DESTROY_NOTIFY 17
# define KEY_ESC 65307

typedef int	argb;
typedef int mat3[9];

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
	void	*img;
	char	*img_data;
	t_ivec3	win_dim;
	int		**map;
	t_ivec3	map_dim;
	int		line_color;
}	t_rcontext;

argb	uni_rgb(int r, int g, int b);
void	t_ivec3_init(t_ivec3 *vec);
void	plot(void *img_data, int *x, int *y, argb color);
void	draw_line(t_rcontext *cont, t_ivec2 start, t_ivec2 end, argb color);

#endif
