/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:41:00 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/03 18:45:54 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <fcntl.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 600
# define WIN_TITLE "FdF"

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

#endif
