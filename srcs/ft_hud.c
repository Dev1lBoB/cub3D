/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:49:37 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:29:41 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

/*
** ty = 0
** mv = 1
** x = 2
** y = 3
** dop = 4
** mvy = 5
*/

void	ft_hb(t_flat *flat, t_text *tex, unsigned int col)
{
	int				it[5];
	double			cx;
	double			cy;
	unsigned int	color;

	cx = 0.75 * 1024 / flat->map->size_x;
	cy = 0.75 * 768 / flat->map->size_y;
	it[1] = flat->map->size_x / 10 - tex->w / cx;
	it[2] = 0;
	while (it[2]++ < (tex->w / cx - 1) && it[2] < flat->map->size_x)
	{
		tex->x = it[2] * cx;
		(tex->x >= tex->w) ? tex->x = tex->w - 1 : 0;
		it[3] = flat->map->size_y - tex->h / cy;
		it[4] = 0;
		while (it[3] < flat->map->size_y - 1)
		{
			it[3]++;
			it[4]++;
			it[0] = it[4] * cy;
			it[0] >= tex->h ? it[0] = tex->h - 1 : 0;
			color = ft_get_color(it[0], tex);
			(color != col) ? ft_mmpp(flat, it[2] + it[1], it[3], color) : 0;
		}
	}
}

void	ft_hd(t_flat *flat, t_text *tex, unsigned int col, float a)
{
	int				it[5];
	double			cx;
	double			cy;
	unsigned int	color;

	cx = 8 * 1024 / flat->map->size_x;
	cy = 8 * 768 / flat->map->size_y;
	it[1] = flat->map->size_x / a - tex->w / cx;
	it[2] = 0;
	while (it[2]++ < (tex->w / cx - 1) && it[2] < flat->map->size_x)
	{
		tex->x = it[2] * cx;
		(tex->x >= tex->w) ? tex->x = tex->w - 1 : 0;
		it[3] = flat->map->size_y - tex->h / cy;
		it[4] = 0;
		while (it[3] < flat->map->size_y - 1)
		{
			it[3]++;
			it[4]++;
			it[0] = it[4] * cy;
			it[0] >= tex->h ? it[0] = tex->h - 1 : 0;
			color = ft_get_color(it[0], tex);
			(color != col) ? ft_mmpp(flat, it[2] + it[1], it[3], color) : 0;
		}
	}
}

void	ft_pb(t_flat *flat, t_text *tex, unsigned int col)
{
	int				it[6];
	double			cx;
	double			cy;
	unsigned int	color;

	cx = 1.2 * 1024 / flat->map->size_x;
	cy = 1.2 * 768 / flat->map->size_y;
	it[1] = flat->map->size_x / 5 - tex->w / cx;
	it[2] = flat->map->size_y / 1.01 - tex->h / cy;
	it[3] = 0;
	while (it[3]++ < (tex->w / cx - 1) && it[3] < flat->map->size_x)
	{
		tex->x = it[3] * cx;
		tex->x >= tex->w ? tex->x = tex->w - 1 : 0;
		it[4] = flat->map->size_y - tex->h / cy - it[2];
		it[5] = 0;
		while (it[4]++ < flat->map->size_y - 1 - it[2])
		{
			it[5]++;
			it[0] = it[5] * cy;
			it[0] >= tex->h ? it[0] = tex->h - 1 : 0;
			color = ft_get_color(it[0], tex);
			(color != col) ? ft_mmpp(flat, it[3] + it[1], it[4], color) : 0;
		}
	}
}

void	ft_ab(t_flat *flat, t_text *tex, unsigned int col)
{
	int				it[5];
	double			cx;
	double			cy;
	unsigned int	color;

	cx = 1.1 * 1024 / flat->map->size_x;
	cy = 1.1 * 768 / flat->map->size_y;
	it[1] = flat->map->size_x / 1.1 - tex->w / cx;
	it[2] = 0;
	while (it[2]++ < (tex->w / cx - 1) && it[2] < flat->map->size_x)
	{
		tex->x = it[2] * cx;
		(tex->x >= tex->w) ? tex->x = tex->w - 1 : 0;
		it[3] = flat->map->size_y - tex->h / cy;
		it[4] = 0;
		while (it[3] < flat->map->size_y - 1)
		{
			it[3]++;
			it[4]++;
			it[0] = it[4] * cy;
			it[0] >= tex->h ? it[0] = tex->h - 1 : 0;
			color = ft_get_color(it[0], tex);
			(color != col) ? ft_mmpp(flat, it[2] + it[1], it[3], color) : 0;
		}
	}
}
