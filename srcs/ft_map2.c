/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:34:49 by wpersimm          #+#    #+#             */
/*   Updated: 2021/07/17 13:16:56 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

static int	ft_wrong_symbol2(t_map *map, int i, int j, int flag)
{
	while (MAP[++i])
	{
		j = -1;
		while (MAP[i][++j])
		{
			if (!ft_ismap(MAP[i][j]) && MAP[i][j] != 49 &&
			MAP[i][j] != 32 && MAP[i][j] != 50)
				return (1);
			if (ft_isspr(MAP[i][j]))
			{
				map->sc++;
				if (MAP[i][j] == 'U' || MAP[i][j] == 'B')
					map->ec++;
			}
			if ((MAP[i][j] == 'N' || MAP[i][j] == 'S' ||
			MAP[i][j] == 'W' || MAP[i][j] == 'E'))
			{
				flag += 2;
				if (flag != 2)
					return (1);
				ft_location(map, i, j);
			}
		}
	}
	return flag == 2 ? 0 : 1;
}

int			ft_wrong_symbol(t_map *map)
{
	int		i;
	int		flag;

	flag = 0;
	i = -1;
	if (ft_wrong_symbol2(map, i, 0, flag))
		return (1);
	return (0);
}

int			ft_validmap(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (ft_wrong_symbol(map))
		return (0);
	while (MAP[i][++j])
		if (ft_ismap(MAP[i][j]))
			return (0);
	while (MAP[++i + 1])
	{
		j = -1;
		if (ft_ismap(MAP[i][++j]))
			return (0);
		while (MAP[i][++j])
			if (ft_bolshoe_uslovie(map, i, j))
				return (0);
	}
	j = -1;
	while (MAP[i][++j])
		if (ft_ismap(MAP[i][j]))
			return (0);
	return (1);
}
