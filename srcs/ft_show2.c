/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:17:30 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:33:07 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_drawtop(t_flat *flat, t_text *tex)
{
	int		y;

	y = flat->map->size_y / flat->ray.jump + 1;
	while (--y > 0)
	{
		flat->tp.ray_dirx0 = DIR_X - PLAN_X;
		flat->tp.ray_diry0 = DIR_Y - PLAN_Y;
		flat->tp.ray_dirx1 = DIR_X + PLAN_X;
		flat->tp.ray_diry1 = DIR_Y + PLAN_Y;
		flat->tp.p = -y + flat->map->size_y / flat->ray.jump;
		flat->tp.row_dist = flat->map->size_y * 0.5 / flat->tp.p;
		flat->tp.f_stepx = flat->tp.row_dist *
		(flat->tp.ray_dirx1 - flat->tp.ray_dirx0) / flat->map->size_x;
		flat->tp.f_stepy = flat->tp.row_dist *
		(flat->tp.ray_diry1 - flat->tp.ray_diry0) / flat->map->size_x;
		flat->tp.floorx = X + flat->tp.row_dist * flat->tp.ray_dirx0;
		flat->tp.floory = Y + flat->tp.row_dist * flat->tp.ray_diry0;
		ft_drawgates1(flat, tex, y, 0);
	}
}

void	ft_drawbot(t_flat *flat, t_text *tex)
{
	int		y;

	y = flat->map->size_y / flat->ray.jump + 1;
	while (++y < flat->map->size_y)
	{
		flat->bt.ray_dirx0 = DIR_X - PLAN_X;
		flat->bt.ray_diry0 = DIR_Y - PLAN_Y;
		flat->bt.ray_dirx1 = DIR_X + PLAN_X;
		flat->bt.ray_diry1 = DIR_Y + PLAN_Y;
		flat->bt.p = y - flat->map->size_y / flat->ray.jump;
		flat->bt.row_dist = flat->map->size_y * 0.5 / flat->bt.p;
		flat->bt.f_stepx = flat->bt.row_dist *
		(flat->bt.ray_dirx1 - flat->bt.ray_dirx0) / flat->map->size_x;
		flat->bt.f_stepy = flat->bt.row_dist *
		(flat->bt.ray_diry1 - flat->bt.ray_diry0) / flat->map->size_x;
		flat->bt.floorx = X + flat->bt.row_dist * flat->bt.ray_dirx0;
		flat->bt.floory = Y + flat->bt.row_dist * flat->bt.ray_diry0;
		ft_drawgates2(flat, tex, y, 0);
	}
}

void	ft_target(t_flat flat)
{
	int		i;

	i = flat.map->size_x / 2 - flat.map->size_x / 100 - 1;
	while (++i <= flat.map->size_x / 2 + flat.map->size_x / 100)
		ft_mmpp(&flat, i, flat.map->size_y / 2, 0xffffff);
	i = flat.map->size_y / 2 - flat.map->size_y / 100 - 1;
	while (++i <= flat.map->size_y / 2 + flat.map->size_y / 100)
		ft_mmpp(&flat, flat.map->size_x / 2, i, 0xffffff);
}

/*
** ty = 0
** mv = 1
** x = 2
** y = 3
** dop = 4
** mvy = 5
*/

void	ft_gun(t_flat *flat, t_text *tex, unsigned int col)
{
	int				it[5];
	double			cx;
	double			cy;
	unsigned int	color;

	cx = 1.0 * 1500 / flat->map->size_x;
	cy = 1.0 * 1000 / flat->map->size_y;
	it[1] = flat->map->size_x / 1.2 - tex->w / cx;
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
