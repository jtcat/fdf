/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:47:10 by joaoteix          #+#    #+#             */
/*   Updated: 2023/03/04 16:09:04 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	t_vec3_init(t_vec3 *vector)
{
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
}

int_rgb	uni_rgb(int r, int g , int b)
{
	return (b | (g << 8) | (r << 16));
}
