/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:32:49 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 00:34:03 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

static void	ft_validdata2(t_map *map, int fd)
{
	int		z;

	(map->size_x < 1 || map->size_y < 0) ? ft_errormap2(fd, map) : 0;
	((z = open(map->text_so, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_no, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_we, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_ea, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_s, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
}

void		ft_validdata(t_map *map, int fd)
{
	int		z;

	ft_validdata2(map, fd);
	if (ft_strncmp(map->text_nt, "none", ft_strlen(map->text_nt)) != 0)
	{
		((z = open(map->text_nt, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
		close(z);
	}
	((z = open(map->text_cl, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_fl, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_en, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_en2, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	((z = open(map->text_en3, O_RDONLY)) == -1) ? ft_errormap2(fd, map) : 0;
	close(z);
	z = -1;
	while (++z < 3)
		if (map->ceilling[z] > 255 || map->floor[z] > 255)
			ft_errormap2(fd, map);
	(!ft_validmap(map)) ? ft_errormap2(fd, map) : 0;
}
