/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:56:36 by joaoteix          #+#    #+#             */
/*   Updated: 2023/04/21 18:09:01 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_map_width(char *filename)
{
	char	*line;
	int		lines;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	lines = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		lines++;
	}
	close(fd);
	return (lines);
}

t_ivec3	arr_atoi(int **dest, char *str)
{
	char	**strarr;
	t_ivec3	size;
	int		i;

	strarr = ft_split(str, ' ');
	free(str);
	t_ivec3_init(&size);
	if (!strarr)
		return (size);
	while (strarr[size.x])
		size.x++;
	*dest = malloc(sizeof(int) * size.x);
	i = 0;
	while (i < size.x)
	{
		(*dest)[i] = ft_atoi(strarr[i]);
		if ((*dest)[i] > size.z)
			size.z = (*dest)[i];
		free(strarr[i++]);
	}
	free(strarr);
	return (size);
}

t_ivec3	read_map(int ***ref_map, char *filename)
{
	t_ivec3	dim;
	t_ivec3	aux_dim;
	int		y;
	int		fd;

	dim.y = get_map_width(filename);
	*ref_map = malloc(sizeof(int *) * dim.y);
	fd = open(filename, O_RDONLY);
	y = 0;
	aux_dim = arr_atoi(*ref_map + y++, get_next_line(fd));
	dim.x = aux_dim.x;
	dim.z = aux_dim.z;
	while (y < dim.y)
	{
		aux_dim = arr_atoi(*ref_map + y++, get_next_line(fd));
		if (aux_dim.x != dim.x)
		{
			while (y >= 0)
				free((*ref_map)[y--]);			
			free(*ref_map);
			close(fd);
			exit(EXIT_FAILURE);
		}
		if (aux_dim.z > dim.z)
			dim.z = aux_dim.z;
	}
	close(fd);
	return (dim);
}

int	main(int argc, char **argv)
{
	t_ivec3	map_dim;
	int		**map;

	if (argc != 2)
	{
		ft_putstr_fd("fdf: Invalid number of arguments.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	map_dim = read_map(&map, argv[1]);
	render_main(map, map_dim);
}
