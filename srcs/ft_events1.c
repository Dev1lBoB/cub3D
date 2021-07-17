/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:27:18 by wpersimm          #+#    #+#             */
/*   Updated: 2021/07/17 12:40:49 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_hl(t_flat *flat)
{
	int		x;

	if (flat->MAP[(int)Y][(int)X] == 'H' && flat->map->loc.hp != 100)
	{
		x = -1;
		flat->map->loc.hp += 32;
		flat->MAP[(int)Y][(int)X] = 48;
		while (++x < flat->map->sc)
			if (flat->spr[x].x == (int)X && flat->spr[x].y == (int)Y)
			{
				flat->spr[x].type = 48;
				break ;
			}
		if (flat->map->loc.hp > 100)
			flat->map->loc.hp = 100;
		flat->hcc = 1;
		ft_heal();
	}
}

static void	ft_en(t_flat *flat)
{
	int		c;

	c = -1;
	while (++c < flat->map->sc)
		if (flat->spr[c].type == 'U' || flat->spr[c].type == 'Z' ||
		flat->spr[c].type == 'X')
		{
			ft_enemy_ray(flat, c);
			if (flat->spr[c].flag == 1 && flat->spr[c].fire == 0)
				flat->spr[c].fire = 1;
			flat->spr[c].flag == 0 ? flat->spr[c].fire = 0 : 0;
			if (flat->spr[c].fire != 0 && flat->spr[c].fire < 25)
				flat->spr[c].fire++;
			if (flat->spr[c].fire == 25)
			{
				flat->spr[c].type = 'X';
				flat->spr[c].fire = 0;
				flat->map->loc.hp -= 8 + flat->map->loc.lvl * 2;
				if (flat->map->loc.hp > 0)
				{
					flat->scc = 1;
					ft_dmg();
				}
			}
		}
}

static void	ft_dt(t_flat *flat)
{
	int		c;

	c = -1;
	if (flat->map->loc.hp <= 0)
	{
		X = flat->map->loc.x_s;
		Y = flat->map->loc.y_s;
		flat->map->loc.life--;
		flat->map->loc.hp = 100;
		while (++c < flat->map->sc)
			if (flat->spr[c].type == 'U' || flat->spr[c].type == 'Z' ||
			flat->spr[c].type == 'X')
				flat->spr[c].fire = 0;
		ft_death();
	}
	if (flat->map->loc.life == 0)
	{
		ft_putstr_fd("Your final score is: ", 2);
		ft_putnbr_fd(flat->map->loc.fscore, 2);
		write(2, "\n", 1);
		system("killall afplay");
		exit(0);
	}
}

int			ft_funcs(t_flat *flat, int x, int y)
{
	ft_turn(flat);
	if (!(ft_events0(flat, x, y)))
		return (0);
	ft_hl(flat);
	ft_en(flat);
	ft_dt(flat);
	return (1);
}
