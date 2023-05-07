/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:56:36 by joaoteix          #+#    #+#             */
/*   Updated: 2023/05/07 14:13:31 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

int	get_map_width(char *filename)
{
	char	*line;
	int		lines;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("fdf: unable to read file or it does not exist.\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
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

int	arr_atoi(int **dest, char *str, int z_minmax[2])
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
		z_minmax[0] = fmin(z_minmax[0], (*dest)[i]);
		z_minmax[1] = fmax(z_minmax[1], (*dest)[i]);
		free(strarr[i++]);
	}
	free(strarr);
	return (len);
}

t_ivec3	read_map(int ***ref_map, char *filename)
{
	t_ivec3	dim;
	int		z_minmax[2];
	int		y;
	int		fd;

	dim = (t_ivec3){INT_MAX, get_map_width(filename), 0};
	*ref_map = malloc(sizeof(int *) * dim.y);
	fd = open(filename, O_RDONLY);
	z_minmax[0] = INT_MAX;
	z_minmax[1] = INT_MIN;
	y = 0;
	while (y < dim.y)
		dim.x = fmin(dim.x, arr_atoi(*ref_map + y++,
					get_next_line(fd), z_minmax));
	dim.z = z_minmax[1] - z_minmax[0];
	if (dim.y == 0)
	{
		dim.x = 0;
		dim.z = 0;
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
