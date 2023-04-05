/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoteix <joaoteix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:56:36 by joaoteix          #+#    #+#             */
/*   Updated: 2023/04/05 15:10:15 by joaoteix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_map_height(char *filename)
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
	int		arrlen;
	int		i;

	strarr = ft_split(str, ' ');
	free(str);
	if (!strarr)
		return (0);
	arrlen = 0;
	while (strarr[arrlen])
		arrlen++;
	*dest = malloc(sizeof(int) * arrlen);
	i = 0;
	while (i < arrlen)
	{
		(*dest)[i] = ft_atoi(strarr[i]);
		free(strarr[i++]);
	}
	free(strarr);
	return (arrlen);
}

t_ivec2	read_map(int ***ref_map, char *filename)
{
	t_ivec2	dim;
	int		y;
	int		fd;

	dim.y = get_map_height(filename);
	*ref_map = malloc(sizeof(int *) * dim.y);
	fd = open(filename, O_RDONLY);
	y = 0;
	while (y < dim.y)
		dim.x = arr_atoi(*ref_map + y++, get_next_line(fd));
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
