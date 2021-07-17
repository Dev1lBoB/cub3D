/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 03:39:41 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/24 02:43:24 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_bmp_data(t_flat *flat, int size, int fd)
{
	unsigned char	*data;
	int				f_size;

	data = ft_calloc(14, sizeof(unsigned char));
	f_size = 54 + (flat->bpp / 8 * flat->map->size_x + size)
	* flat->map->size_y;
	data[0] = (unsigned char)'B';
	data[1] = (unsigned char)'M';
	data[2] = (unsigned char)f_size;
	data[3] = (unsigned char)(f_size >> 8);
	data[4] = (unsigned char)(f_size >> 16);
	data[5] = (unsigned char)(f_size >> 24);
	data[10] = (unsigned char)54;
	write(fd, data, 14);
	free(data);
}

void	ft_bmp_image_data(t_flat *flat, int fd)
{
	unsigned char	*data;

	if (!(data = ft_calloc(40, sizeof(unsigned char))))
	{
		write(2, "Error:\nMalloc abort\n", 20);
		exit(0);
	}
	data[0] = (unsigned char)40;
	data[4] = (unsigned char)flat->map->size_x;
	data[5] = (unsigned char)(flat->map->size_x >> 8);
	data[6] = (unsigned char)(flat->map->size_x >> 16);
	data[7] = (unsigned char)(flat->map->size_x >> 24);
	data[8] = (unsigned char)flat->map->size_y;
	data[9] = (unsigned char)(flat->map->size_y >> 8);
	data[10] = (unsigned char)(flat->map->size_y >> 16);
	data[11] = (unsigned char)(flat->map->size_y >> 24);
	data[12] = (unsigned char)1;
	data[14] = (unsigned char)(flat->bpp);
	write(fd, data, 40);
	free(data);
}

void	ft_merr(void)
{
	write(2, "Error:\nMalloc abort\n", 20);
	exit(0);
}

void	ft_create_bmp(t_flat *flat)
{
	int				fd;
	int				size;
	int				i;
	unsigned char	*data;

	i = flat->map->size_y + 1;
	if (!(data = ft_calloc(4, sizeof(unsigned char))))
		ft_merr();
	if ((fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
	{
		write(2, "Error:\nCannot open file\n", 24);
		exit(0);
	}
	size = (4 - (flat->map->size_x * flat->bpp / 8) % 4) % 4;
	ft_bmp_data(flat, size, fd);
	ft_bmp_image_data(flat, fd);
	while (--i >= 0)
	{
		write(fd, flat->adr + (i * flat->map->size_x * flat->bpp / 8),
		flat->ll);
		write(fd, data, size);
	}
	close(fd);
	exit(0);
}
