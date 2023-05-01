/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:56:36 by joaoteix          #+#    #+#             */
/*   Updated: 2023/04/23 14:24:25 by joaoteix         ###   ########.fr       */
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

int	arr_atoi(int **dest, char *str)
{
	char	**strarr;
	int		len;
	int		i;

	strarr = ft_split(str, ' ');
	free(str);
	if (!strarr)
		return (-1);
	len = 0;
	while (strarr[len])
		len++;
	*dest = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		(*dest)[i] = ft_atoi(strarr[i]);
		free(strarr[i++]);
	}
	free(strarr);
	return (len);
}

t_ivec2	read_map(int ***ref_map, char *filename)
{
	t_ivec2	dim;
	int		tmp_x;
	int		y;
	int		fd;

	dim = (t_ivec2){0, get_map_width(filename)};
	*ref_map = malloc(sizeof(int *) * dim.y);
	fd = open(filename, O_RDONLY);
	y = 0;
	while (y < dim.y)
	{
		tmp_x = arr_atoi(*ref_map + y++, get_next_line(fd));
		if (dim.x == 0 || tmp_x < dim.x)
			dim.x = tmp_x;
	}
	close(fd);
	return (dim);
}

int	main(int argc, char **argv)
{
	t_ivec2	map_dim;
	int		**map;

	if (argc != 2)
	{
		ft_putstr_fd("fdf: Invalid number of arguments.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	map_dim = read_map(&map, argv[1]);
	render_main(map, map_dim);
}
