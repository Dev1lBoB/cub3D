/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:07:59 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 00:33:44 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

void	ft_floor(t_map *map, char *line, char **str, int fd)
{
	int		i;

	i = 0;
	while (line[i] == 32)
		i++;
	(!ft_isdigit(line[i])) ? ft_errormap(str, fd, map) : 0;
	map->floor[0] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		ft_errormap(str, fd, map);
	while (line[i] == 32)
		i++;
	(!ft_isdigit(line[i])) ? ft_errormap(str, fd, map) : 0;
	map->floor[1] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	(line[i++] != ',') ? ft_errormap(str, fd, map) : 0;
	while (line[i] == 32)
		i++;
	(!ft_isdigit(line[i])) ? ft_errormap(str, fd, map) : 0;
	map->floor[2] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	ft_strcheck(&line[i], fd, str, map);
}

void	ft_ceilling(t_map *map, char *line, char **str, int fd)
{
	int		i;

	i = 0;
	while (line[i] == 32)
		i++;
	(!ft_isdigit(line[i])) ? ft_errormap(str, fd, map) : 0;
	map->ceilling[0] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',')
		ft_errormap(str, fd, map);
	while (line[i] == 32)
		i++;
	(!ft_isdigit(line[i])) ? ft_errormap(str, fd, map) : 0;
	map->ceilling[1] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	(line[i++] != ',') ? ft_errormap(str, fd, map) : 0;
	while (line[i] == 32)
		i++;
	(!ft_isdigit(line[i])) ? ft_errormap(str, fd, map) : 0;
	map->ceilling[2] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	ft_strcheck(&line[i], fd, str, map);
}

void	ft_colors(t_map *map, int fd, char **loin)
{
	char	*line;
	char	ch;
	int		i;

	i = 0;
	line = *loin;
	while (line[i] == 32)
		i++;
	ch = line[i++];
	if (ch == 'F' && map->floor[0] == -1)
		ft_floor(map, &line[i], &line, fd);
	else if (ch == 'C' && map->ceilling[0] == -1)
		ft_ceilling(map, &line[i], &line, fd);
	else
		ft_errormap(&line, fd, map);
	free(line);
}

void	ft_strcheck(char *line, int fd, char **str, t_map *map)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32)
			ft_errormap(str, fd, map);
		i++;
	}
}
