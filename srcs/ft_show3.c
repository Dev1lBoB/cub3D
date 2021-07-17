/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:20:28 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:33:29 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_drawgates1(t_flat *flat, t_text *tex, int y, int ty)
{
	int	x;

	x = -1;
	while (++x < flat->map->size_x)
	{
		flat->tp.cellx = (int)(flat->tp.floorx);
		flat->tp.celly = (int)(flat->tp.floory);
		tex->x = (int)(tex->w *
		(flat->tp.floorx - flat->tp.cellx)) & (tex->w - 1);
		ty = (int)(tex->h * (flat->tp.floory - flat->tp.celly)) & (tex->h - 1);
		flat->tp.floorx += flat->tp.f_stepx;
		flat->tp.floory += flat->tp.f_stepy;
		ft_mmpp(flat, x, y, ft_get_color(ty, tex));
	}
}

void	ft_drawgates2(t_flat *flat, t_text *tex, int y, int ty)
{
	int	x;

	x = -1;
	while (++x < flat->map->size_x)
	{
		flat->bt.cellx = (int)(flat->bt.floorx);
		flat->bt.celly = (int)(flat->bt.floory);
		tex->x = (int)(tex->w *
		(flat->bt.floorx - flat->bt.cellx)) & (tex->w - 1);
		ty = (int)(tex->h * (flat->bt.floory - flat->bt.celly)) & (tex->h - 1);
		flat->bt.floorx += flat->bt.f_stepx;
		flat->bt.floory += flat->bt.f_stepy;
		ft_mmpp(flat, x, y, ft_get_color(ty, tex));
	}
}

void	ft_screen(t_flat *flat, t_text *tex, unsigned int col)
{
	int				it[5];
	double			cx;
	double			cy;
	unsigned int	color;

	cx = 1.87 * 1024 / flat->map->size_x;
	cy = 2.815 * 384 / flat->map->size_y;
	it[1] = flat->map->size_x / 1 - tex->w / cx;
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
