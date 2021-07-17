/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:58:56 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/24 02:35:31 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

int		ft_ismap(char a)
{
	if (a == 48 || a == 50 || a == 'N' || a == 'S' || a == 'W' || a == 'E'
	|| a == 'A' || a == 'T' || a == 'H' || a == 'U' || a == 'G')
		return (1);
	return (0);
}

int		ft_isspr(char a)
{
	if (a == 50 || a == 'A' || a == 'T' || a == 'H' || a == 'U'
	|| a == 'Z' || a == 'G')
		return (1);
	return (0);
}

int		ft_bolshoe_uslovie(t_map *map, int i, int j)
{
	if (ft_ismap(MAP[i][j]) && (MAP[i][j - 1] == 32 ||
	MAP[i][j + 1] == 32 || MAP[i][j + 1] == 0 || MAP[i + 1][j] == 32
	|| MAP[i + 1][j] == 0 || MAP[i - 1][j] == 32 || MAP[i - 1][j] == 0
	|| j > (int)ft_strlen(MAP[i - 1]) || MAP[i - 1][j - 1] == 32
	|| MAP[i - 1][j + 1] == 32 || MAP[i - 1][j + 1] == 0
	|| MAP[i + 1][j - 1] == 32 || MAP[i + 1][j - 1] == 0
	|| MAP[i + 1][j + 1] == 0 || MAP[i + 1][j + 1] == 32
	|| j > (int)ft_strlen(MAP[i + 1])))
		return (1);
	return (0);
}

int		ft_bolshoe_uslovie2(char *line, int j)
{
	if ((line[j] == 'S' && line[j + 1] == 'O' && line[j + 2] == 32) ||
		(line[j] == 'N' && line[j + 1] == 'O' && line[j + 2] == 32) ||
		(line[j] == 'W' && line[j + 1] == 'E' && line[j + 2] == 32) ||
		(line[j] == 'E' && line[j + 1] == 'A' && line[j + 2] == 32) ||
		(line[j] == 'N' && line[j + 1] == 'T' && line[j + 2] == 32) ||
		(line[j] == 'F' && line[j + 1] == 'L' && line[j + 2] == 32) ||
		(line[j] == 'C' && line[j + 1] == 'L' && line[j + 2] == 32) ||
		(line[j] == 'M' && line[j + 1] == 'C' && line[j + 2] == 32) ||
		(line[j] == 'E' && line[j + 1] == 'N' && line[j + 2] == 32))
		return (1);
	return (0);
}

void	ft_size_check(t_map *map)
{
	if (map->size_x > 2560)
		map->size_x = 2560;
	if (map->size_y > 1395)
		map->size_y = 1395;
}
