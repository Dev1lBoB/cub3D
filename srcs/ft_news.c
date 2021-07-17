/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_news.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:04:55 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/24 02:22:28 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

static int	ft_news22(t_map *map, int *br, char *news, char **line)
{
	int		a;

	a = 0;
	if (!ft_strncmp(news, "SO", 2) && map->text_so == NULL)
	{
		if (!(map->text_so = ft_substr(*line, br[1], br[0] - br[1] + 1)))
			a = ft_malerr(line, map);
	}
	else if (!ft_strncmp(news, "NO", 2) && map->text_no == NULL)
	{
		if (!(map->text_no = ft_substr(*line, br[1], br[0] - br[1] + 1)))
			a = ft_malerr(line, map);
	}
	else if (!ft_strncmp(news, "WE", 2) && map->text_we == NULL)
	{
		if (!(map->text_we = ft_substr(*line, br[1], br[0] - br[1] + 1)))
			a = ft_malerr(line, map);
	}
	else
		return (0);
	return (a == -1) ? -1 : 1;
}

static int	ft_news2(t_map *map, int *br, char *news, char **line)
{
	int		a;

	a = 0;
	if ((a = ft_news22(map, br, news, line)) != 0)
		return (a == -1) ? -1 : 1;
	else
	{
		if (!ft_strncmp(news, "EA", 2) && map->text_ea == NULL)
		{
			if (!(map->text_ea = ft_substr(*line, br[1], br[0] - br[1] + 1)))
				a = ft_malerr(line, map);
		}
		else
			return (0);
	}
	return (a == -1) ? -1 : 1;
}

static int	ft_news33(t_map *map, int *br, char *news, char **line)
{
	int		a;

	a = 0;
	if (!ft_strncmp(news, "FL", 2) && map->text_fl == NULL)
	{
		if (!(map->text_fl = ft_substr(*line, br[1], br[0] - br[1] + 1)))
			a = ft_malerr(line, map);
	}
	else if (!ft_strncmp(news, "CL", 2) && map->text_cl == NULL)
	{
		if (!(map->text_cl = ft_substr(*line, br[1], br[0] - br[1] + 1)))
			a = ft_malerr(line, map);
	}
	else if (!ft_strncmp(news, "EN", 2) && map->text_en == NULL)
	{
		if (!(map->text_en = ft_substr(*line, br[1], br[0] - br[1] + 1)))
			a = ft_malerr(line, map);
	}
	else
		return (0);
	return (a == -1) ? -1 : 1;
}

static int	ft_news3(t_map *map, int *br, char *news, char **line)
{
	int		a;

	a = 0;
	if ((a = ft_news33(map, br, news, line)) != 0)
		return (a == -1) ? -1 : 1;
	else
	{
		if (!ft_strncmp(news, "NT", 2))
		{
			if (!(map->text_nt = ft_substr(*line, br[1], br[0] - br[1] + 1)))
				a = ft_malerr(line, map);
		}
		else
			return (0);
	}
	return (a == -1) ? -1 : 1;
}

int			ft_news(t_map *map, int *br, char *news, char **line)
{
	int		a;

	a = 0;
	if ((a = ft_news2(map, br, news, line)) != 0)
		return (a == -1) ? -1 : 1;
	else
	{
		if ((a = ft_news3(map, br, news, line)) != 0)
			return (a == -1) ? -1 : 1;
		else
		{
			if (!ft_strncmp(news, "MC", 2) && map->text_mc == NULL)
			{
				if (!(map->text_mc = ft_substr(*line, br[1],
				br[0] - br[1] + 1)))
					a = ft_malerr(line, map);
			}
			else
				return (0);
		}
	}
	return (a == -1) ? -1 : 1;
}
