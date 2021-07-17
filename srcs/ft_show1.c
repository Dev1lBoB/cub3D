/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:13:10 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/22 04:27:58 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_pb2(t_flat *flat)
{
	if (flat->map->loc.score >= (float)flat->map->ec / 10 * 7 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 8)
		ft_pb(flat, &flat->pr[7], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 * 8 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 9)
		ft_pb(flat, &flat->pr[8], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 * 9 &&
	flat->map->loc.score < (float)flat->map->ec)
		ft_pb(flat, &flat->pr[9], 0xff0000);
	else if (flat->map->loc.score == flat->map->ec)
		ft_pb(flat, &flat->pr[10], 0xff0000);
}

static void	ft_pb1(t_flat *flat)
{
	if (flat->map->loc.score == 0 ||
	flat->map->loc.score < (float)flat->map->ec / 10)
		ft_pb(flat, &flat->pr[0], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 2)
		ft_pb(flat, &flat->pr[1], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 * 2 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 3)
		ft_pb(flat, &flat->pr[2], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 * 3 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 4)
		ft_pb(flat, &flat->pr[3], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 * 4 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 5)
		ft_pb(flat, &flat->pr[4], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 * 5 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 6)
		ft_pb(flat, &flat->pr[5], 0xff0000);
	else if (flat->map->loc.score >= (float)flat->map->ec / 10 * 6 &&
	flat->map->loc.score < (float)flat->map->ec / 10 * 7)
		ft_pb(flat, &flat->pr[6], 0xff0000);
	else
		ft_pb2(flat);
}

static void	ft_matter(t_flat *flat)
{
	if (flat->map->loc.hp > 90 && flat->map->loc.hp <= 100)
		ft_hb(flat, &flat->hp[7], 0xf6f6f6);
	if (flat->map->loc.hp > 80 && flat->map->loc.hp <= 90)
		ft_hb(flat, &flat->hp[6], 0xf6f6f6);
	if (flat->map->loc.hp > 70 && flat->map->loc.hp <= 80)
		ft_hb(flat, &flat->hp[5], 0xf6f6f6);
	if (flat->map->loc.hp > 60 && flat->map->loc.hp <= 70)
		ft_hb(flat, &flat->hp[4], 0xf6f6f6);
	if (flat->map->loc.hp > 50 && flat->map->loc.hp <= 60)
		ft_hb(flat, &flat->hp[3], 0xf6f6f6);
	if (flat->map->loc.hp > 40 && flat->map->loc.hp <= 50)
		ft_hb(flat, &flat->hp[2], 0xf6f6f6);
	if (flat->map->loc.hp > 30 && flat->map->loc.hp <= 40)
		ft_hb(flat, &flat->hp[1], 0xf6f6f6);
	if (flat->map->loc.hp > 20 && flat->map->loc.hp <= 30)
		ft_hb(flat, &flat->hp[0], 0xf6f6f6);
	if (flat->map->loc.hp > 10 && flat->map->loc.hp <= 20)
		ft_hb(flat, &flat->hp[8], 0xf6f6f6);
	if (flat->map->loc.hp >= 0 && flat->map->loc.hp <= 10)
		ft_hb(flat, &flat->hp[9], 0xf6f6f6);
	if (flat->map->loc.life > 0)
		ft_hd(flat, &flat->hd, 0, 5);
	if (flat->map->loc.life > 1)
		ft_hd(flat, &flat->hd, 0, 3.55);
	flat->map->loc.life > 2 ? ft_hd(flat, &flat->hd, 0, 2.75) : 0;
}

static void	ft_putevent(t_flat *flat)
{
	if (flat->scc != 0)
	{
		ft_screen(flat, &flat->sc[0], 0);
		flat->scc = 0;
	}
	if (flat->hcc != 0)
	{
		ft_screen(flat, &flat->sc[1], 0);
		flat->hcc = 0;
	}
	if (flat->acc != 0)
	{
		ft_screen(flat, &flat->sc[2], 0);
		flat->acc = 0;
	}
}

void		ft_show(t_flat *flat)
{
	int		z;
	int		c;

	z = flat->map->size_x;
	c = -1;
	ft_drawbot(flat, &flat->bot);
	ft_drawtop(flat, &flat->top);
	while (--z >= 0)
		flat->map->slen[z] = ft_cast_ray(flat, z);
	ft_draw_spr(flat);
	if (flat->map->loc.fire == 0)
		ft_gun(flat, &flat->gun, 0xff0000);
	else
		ft_gun(flat, &flat->gun2, 0xff0000);
	ft_putevent(flat);
	ft_target(*flat);
	ft_pb1(flat);
	ft_matter(flat);
	ft_ab(flat, &flat->am[flat->map->loc.ammo / 2], 0xff0000);
	mlx_put_image_to_window(flat->mlx, flat->win, flat->img, 0, 0);
	if (flat->save == 1)
	{
		system("killall afplay");
		ft_create_bmp(flat);
	}
}
