/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 04:27:19 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/22 02:22:43 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_spr_dist(t_flat *flat)
{
	int		i;
	int		j;
	t_spr	temp;

	i = -1;
	while (++i < flat->map->sc)
		flat->spr[i].dist = pow(Y - flat->spr[i].y, 2) +
		pow(X - flat->spr[i].x, 2);
	i = -1;
	while (++i < flat->map->sc - 1)
	{
		j = flat->map->sc;
		while (--j > i)
		{
			if (flat->spr[j - 1].dist < flat->spr[j].dist)
			{
				temp = flat->spr[j - 1];
				flat->spr[j - 1] = flat->spr[j];
				flat->spr[j] = temp;
			}
		}
	}
}

static void	ft_tex_choice(t_flat *flat, char ch, t_text *tex)
{
	if (ch == '2')
		ft_spr_text(tex, &flat->sprt.br);
	if (ch == 'A')
		ft_spr_text(tex, &flat->sprt.a);
	if (ch == 'T')
		ft_spr_text(tex, &flat->sprt.t);
	if (ch == 'H')
		ft_spr_text(tex, &flat->sprt.h);
	if (ch == 'R')
		ft_spr_text(tex, &flat->sprt.rk);
	if (ch == 'U')
		ft_spr_text(tex, &flat->sprt.en);
	if (ch == 'Z')
		ft_spr_text(tex, &flat->sprt.en2);
	if (ch == 'X')
		ft_spr_text(tex, &flat->sprt.en3);
}

/*
** -------int-------
** i = 0
** scr = 1
** h = 2
** sy = 3
** ey = 4
** w = 5
** sx = 6
** ex = 7
** d = 8
** ty = 9
** color = 10
** flag = 11
** -----double----
** posx = 0
** posy = 1
** transx = 2
** transy = 3
** inv = 4
*/

static void	ft_ds_c0(t_flat *flat, int it[12], double db[5], t_text *tex)
{
	it[11] = 0;
	ft_tex_choice(flat, flat->spr[it[0]].type, tex);
	db[0] = flat->spr[it[0]].x + 0.5 - X;
	db[1] = flat->spr[it[0]].y + 0.5 - Y;
	db[4] = 1.0 / (PLAN_X * DIR_Y - PLAN_Y * DIR_X);
	db[2] = db[4] * (DIR_Y * db[0] - DIR_X * db[1]);
	db[3] = db[4] * (PLAN_X * db[1] - PLAN_Y * db[0]);
	it[1] = (int)((flat->map->size_x / 2) * (1 + db[2] / db[3]));
	it[2] = ft_abs((int)(flat->map->size_y / db[3]));
	it[4] = it[2] / 2 + flat->map->size_y / flat->ray.jump;
	if (it[4] >= flat->map->size_y)
		it[4] = flat->map->size_y - 1;
	it[5] = ft_abs((int)(flat->map->size_x / db[3]));
	it[6] = -it[5] / 2 + it[1];
	if (it[6] < 0)
	{
		it[6] = 0;
		it[11]++;
	}
	it[7] = it[5] / 2 + it[1];
	if (it[7] >= flat->map->size_x)
	{
		it[7] = flat->map->size_x - 1;
		it[11]++;
	}
}

static void	ft_ds_c1(t_flat *flat, int it[12], double db[5], t_text *tex)
{
	while (it[6] < it[7])
	{
		tex->x = (int)(256 * (it[6] -
		(-it[5] / 2 + it[1])) * tex->w / it[5]) / 256;
		it[3] = -it[2] / 2 + flat->map->size_y / flat->ray.jump;
		if (it[3] < 0)
			it[3] = 0;
		if (db[3] > 0 && it[6] > 0 && it[6] < flat->map->size_x &&
		db[3] < flat->map->slen[it[6]])
			while (it[3] < it[4])
			{
				it[8] = it[3] * 256 - flat->map->size_y /
				flat->ray.jump * 256 + it[2] * 128;
				it[9] = (int)((it[8] * tex->h) / it[2]) / 256;
				it[10] = ft_get_color(it[9], tex);
				if (it[10] != 0)
					ft_mmpp(flat, it[6], it[3], it[10]);
				it[3]++;
			}
		it[6]++;
	}
}

void		ft_draw_spr(t_flat *flat)
{
	int		it[12];
	double	db[5];
	t_text	tex;

	ft_spr_dist(flat);
	it[0] = -1;
	while (++it[0] < flat->map->sc)
	{
		if (flat->spr[it[0]].type == 48 || flat->spr[it[0]].type == 'G')
			continue ;
		ft_ds_c0(flat, it, db, &tex);
		if (it[11] == 2)
			continue ;
		ft_ds_c1(flat, it, db, &tex);
	}
}
