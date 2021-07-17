/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:06:32 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 00:06:13 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

void	ft_data(t_map *map, int fd, int i)
{
	char	*line;
	int		j;

	while (++i < 13)
	{
		j = 0;
		(!(ft_line(fd, &line))) ? ft_malerr(&line, map) : 0;
		while (line[j] == 32)
			j++;
		if (line[j] == 0 || line[j + 1] == 0)
			ft_errormap(&line, fd, map);
		else if (line[j] == 'R')
			ft_size(map, fd, &line);
		else if (ft_bolshoe_uslovie2(line, j))
			ft_walls(map, fd, &line);
		else if (line[j] == 'S' && line[j + 1] == 32)
			ft_sprite(map, fd, &line);
		else if (line[j + 1] == ' ' && (line[j] == 'C' || line[j] == 'F'))
			ft_colors(map, fd, &line);
		else
			ft_errormap(&line, fd, map);
	}
}

void	ft_size(t_map *map, int fd, char **loin)
{
	char	*line;
	int		i;

	i = 0;
	line = *loin;
	while (line[i] == 32)
		i++;
	if (line[i] != 'R')
		ft_errormap(&line, fd, map);
	i++;
	while (line[i] == 32)
		i++;
	if (!ft_isdigit(line[i]))
		ft_errormap(&line, fd, map);
	map->size_x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == 32)
		i++;
	map->size_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	ft_strcheck(&line[i], fd, &line, map);
	free(line);
}

void	ft_walls(t_map *map, int fd, char **loin)
{
	char	*line;
	char	news[3];
	int		br[2];
	int		k;

	k = 0;
	br[0] = 0;
	line = *loin;
	while (line[br[0]] == 32)
		br[0]++;
	ft_novosty(news, line, br);
	while (line[br[0]] == 32)
		br[0]++;
	line[br[0]] == 0 ? ft_errormap(&line, fd, map) : 0;
	br[1] = br[0];
	while (line[br[0]] && line[br[0]] != 32)
		br[0]++;
	if ((k = ft_news(map, br, news, &line)) == -1)
		ft_close(fd);
	else if (!k)
		ft_errormap(&line, fd, map);
	ft_strcheck(&line[br[0]], fd, &line, map);
	free(line);
}

void	ft_sprite(t_map *map, int fd, char **loin)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = *loin;
	while (line[i] == 32)
		i++;
	if (line[i++] != 'S')
		ft_errormap(&line, fd, map);
	while (line[i] == 32)
		i++;
	line[i] == 0 ? ft_errormap(&line, fd, map) : 0;
	j = i;
	while (line[i] && line[i] != 32)
		i++;
	map->text_s = ft_substr(line, j, i - j + 1);
	ft_strcheck(&line[i], fd, &line, map);
	free(line);
}
