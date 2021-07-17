/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:54:18 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 22:07:40 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

void	ft_errormap2(int fd, t_map *map)
{
	int		i;

	i = 0;
	if (map->text_so)
		free(map->text_so);
	if (map->text_no)
		free(map->text_no);
	if (map->text_we)
		free(map->text_we);
	if (map->text_ea)
		free(map->text_ea);
	if (map->text_s)
		free(map->text_s);
	if (MAP)
		while (MAP[i])
			free(MAP[i++]);
	if (MAP)
		free(MAP);
	free(map);
	close(fd);
	write(2, "Error:\nInvalid map\n", 19);
	exit(0);
}

int		ft_malerr(char **line, t_map *map)
{
	if (*line)
		free(*line);
	if (map->text_so)
		free(map->text_so);
	if (map->text_no)
		free(map->text_no);
	if (map->text_we)
		free(map->text_we);
	if (map->text_ea)
		free(map->text_ea);
	if (map->text_s)
		free(map->text_s);
	free(map);
	write(2, "Error:\nMalloc abort\n", 20);
	return (-1);
}

void	ft_errormap(char **line, int fd, t_map *map)
{
	free(*line);
	if (map->text_so)
		free(map->text_so);
	if (map->text_no)
		free(map->text_no);
	if (map->text_we)
		free(map->text_we);
	if (map->text_ea)
		free(map->text_ea);
	if (map->text_s)
		free(map->text_s);
	free(map);
	close(fd);
	write(2, "Error:\nInvalid map\n", 19);
	exit(0);
}

void	ft_close(int fd)
{
	close(fd);
	exit(0);
}
