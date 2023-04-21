/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:41:00 by joaoteix          #+#    #+#             */
/*   Updated: 2023/04/21 17:28:59 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include "unistd.h"
# include <math.h>
# include <X11/X.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 600
# define WIN_TITLE "FdF"

# define DESTROY_NOTIFY 17
# define KEY_ESC 65307

typedef int	argb;
typedef double mat3[9];

typedef struct s_ivec3
{
	int	x;
	int	y;
	int	z;
}	t_ivec3;

typedef struct s_dvec3
{
	double	x;
	double	y;
	double	z;
}	t_dvec3;

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
	char	*img_addr;
	int		color_depth;
	int		line_len;
	int		endian;
	t_ivec3	win_dim;
	int		**raw_map;
	t_ivec3	**proj_map;
	t_ivec3	map_dim;
	int		line_color;
	int		scale;
}	t_rcontext;

argb	uni_rgb(int r, int g, int b);
void	t_ivec3_init(t_ivec3 *vec);
void	t_ivec2_init(t_ivec2 *vec);
void	plot(t_rcontext *ctx, int x, int y, argb color);
void	draw_line(t_rcontext *cont, t_ivec3 start, t_ivec3 end, argb color);
int		render_main(int **map, t_ivec3 dim);
t_ivec3	mat3_vec3_prod(const mat3 mat, t_ivec3 vec);
t_ivec3	vec3_sum(t_ivec3 v1, t_ivec3 v2);

#endif
