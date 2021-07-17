/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:18:43 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 21:54:24 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

void	ft_enemy(t_map *map)
{
	map->text_en2 = ft_strdup(map->text_en);
	map->text_en3 = ft_strdup(map->text_en);
	map->text_en2[ft_strlen(map->text_en2) - 5] = '2';
	map->text_en3[ft_strlen(map->text_en3) - 5] = '3';
}

t_map	*ft_read(char **argv, t_map *map, int a)
{
	int		fd;

	if (a == 0)
		if (!(map = malloc(sizeof(t_map))))
		{
			write(1, "Error: malloc abort\n", 20);
			exit(0);
		}
	ft_start(map);
	fd = a == 0 ? open(argv[1], O_RDONLY) : open(map->text_nt, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: no such file or derictory\n", 33);
		exit(0);
	}
	if (a == 1)
		free(map->text_nt);
	ft_data(map, fd, -1);
	ft_enemy(map);
	ft_maze(map, fd);
	ft_validdata(map, fd);
	close(fd);
	(a == 0) ? ft_finish(map) : ft_sfinish(map);
	return (map);
}
