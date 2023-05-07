/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:41:00 by joaoteix          #+#    #+#             */
/*   Updated: 2023/05/07 13:00:07 by joaoteix         ###   ########.fr       */
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

typedef int		t_argb;
typedef double	t_mat3[9];

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
	int	x;
	int	y;
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
	t_dvec3	**proj_map;
	t_ivec3	map_dim;
	int		line_color;
	double	scale;
}	t_rcontext;

t_argb	uni_rgb(int r, int g, int b);
void	plot(t_rcontext *ctx, int x, int y, t_argb color);
void	draw_line(t_rcontext *cont, t_dvec3 start, t_dvec3 end, t_argb color);
int		render_main(int **map, t_ivec3 dim);
t_dvec3	mat3_dvec3_prod(const t_mat3 mat, t_dvec3 vec);
t_dvec3	dvec3_sum(t_dvec3 v1, t_dvec3 v2);

int		in_range(int lower, int upper, int numb);

void	draw_image(t_rcontext *ctx);
void	project_map(t_rcontext *ctx);

double	calc_scale(t_ivec3 dim);

#endif
