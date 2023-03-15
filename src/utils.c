/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/15 16:20:33 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	t_ivec3_init(t_ivec3 *vector)
{
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
}

i_rgb	uni_rgb(int r, int g , int b)
{
	return (b | (g << 8) | (r << 16));
}
