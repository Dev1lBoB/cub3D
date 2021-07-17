/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:37:10 by wpersimm          #+#    #+#             */
/*   Updated: 2020/11/22 19:33:51 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	*buf[1025];
	char		bufer[ft_bufersize(BUFFER_SIZE) + 1];
	int			z;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	z = 1;
	while (!ft_newline(buf[fd], 0) && z)
	{
		if ((z = read(fd, bufer, BUFFER_SIZE)) < 0)
			return (-1);
		bufer[z] = 0;
		if (!(buf[fd] = ft_strjoin(buf[fd], bufer)))
			return (-1);
	}
	if (!(*line = ft_strdupper(buf[fd])))
		return (-1);
	buf[fd] = ft_strduplic(buf[fd]);
	if (z != 0 && !buf[fd])
		return (-1);
	return ((z) ? 1 : z);
}
