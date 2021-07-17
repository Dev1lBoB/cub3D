/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:08:34 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/24 02:29:45 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

void	ft_start(t_map *map)
{
	map->size_x = -1;
	map->size_y = -1;
	map->text_so = NULL;
	map->text_no = NULL;
	map->text_we = NULL;
	map->text_ea = NULL;
	map->text_en = NULL;
	map->text_en2 = NULL;
	map->text_en3 = NULL;
	map->text_s = NULL;
	map->text_fl = NULL;
	map->text_cl = NULL;
	map->text_mc = NULL;
	map->floor[0] = -1;
	map->ceilling[0] = -1;
	map->map = NULL;
	map->sc = 0;
	map->ec = 0;
	map->loc.score = 0;
}

void	ft_finish(t_map *map)
{
	if ((int)map->loc.dir == (int)(M_PI / 2) ||
	(int)map->loc.dir == (int)(3 * M_PI / 2))
		map->loc.plan_x = 0;
	else if (map->loc.dir == 0)
		map->loc.plan_x = -0.66;
	else
		map->loc.plan_x = 0.66;
	if ((int)map->loc.dir == (int)M_PI || map->loc.dir == 0)
		map->loc.plan_y = 0;
	else if ((int)map->loc.dir == (int)(M_PI / 2))
		map->loc.plan_y = 0.66;
	else
		map->loc.plan_y = -0.66;
	map->loc.dir_x = sin(map->loc.dir);
	map->loc.dir_y = cos(map->loc.dir);
	map->loc.x_s = map->loc.x;
	map->loc.y_s = map->loc.y;
	map->loc.ammo = 8;
	map->loc.fire = 0;
	map->loc.hp = 100;
	map->loc.life = 3;
	map->loc.fscore = 0;
	map->loc.lvl = 0;
	ft_size_check(map);
}

void	ft_sfinish(t_map *map)
{
	if ((int)map->loc.dir == (int)(M_PI / 2) ||
	(int)map->loc.dir == (int)(3 * M_PI / 2))
		map->loc.plan_x = 0;
	else if (map->loc.dir == 0)
		map->loc.plan_x = -0.66;
	else
		map->loc.plan_x = 0.66;
	if ((int)map->loc.dir == (int)M_PI || map->loc.dir == 0)
		map->loc.plan_y = 0;
	else if ((int)map->loc.dir == (int)(M_PI / 2))
		map->loc.plan_y = 0.66;
	else
		map->loc.plan_y = -0.66;
	map->loc.dir_x = sin(map->loc.dir);
	map->loc.dir_y = cos(map->loc.dir);
	map->loc.x_s = map->loc.x;
	map->loc.y_s = map->loc.y;
	map->loc.fire = 0;
}

int		ft_novosty(char *news, char *line, int *br)
{
	news[0] = line[br[0]++];
	news[1] = line[br[0]++];
	news[2] = 0;
	return (2);
}

int		ft_line(int fd, char **line)
{
	int		i;

	i = get_next_line(fd, line);
	if (i == -1)
		return (0);
	while (*line[0] == 0)
	{
		free(*line);
		i = get_next_line(fd, line);
		if (i == -1)
			return (0);
	}
	return (1);
}
