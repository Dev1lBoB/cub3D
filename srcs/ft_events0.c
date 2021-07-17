/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:21:52 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 04:24:39 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_rat(t_flat *flat, int x, int y)
{
	if (x == flat->map->size_x / 2)
	{
		flat->map->loc.turn[0] = 1;
		flat->map->loc.turn[1] = 1;
	}
	if (flat->map->loc.look != 0)
	{
		flat->ray.jump += URS;
		if (flat->ray.jump > 5)
			flat->ray.jump = 5;
		if (flat->ray.jump < 1.2)
			flat->ray.jump = 1.2;
	}
	if (y == flat->map->size_y / 2)
		flat->map->loc.look = 0;
	if (flat->map->loc.pause == 0)
	{
		mlx_mouse_hide();
		mlx_mouse_move(flat->win, flat->map->size_x / 2, flat->map->size_y / 2);
	}
	if (flat->map->loc.pause == 1)
		mlx_mouse_show();
}

static int	ft_fu(t_flat *flat)
{
	if (flat->map->loc.fire == 1)
	{
		flat->ray.jump -= 0.15;
		ft_fire(flat);
		if (flat->map->loc.score == flat->map->ec)
		{
			flat->map->loc.lvl++;
			ft_lvl(flat);
			return (0);
		}
	}
	if (flat->map->loc.use == 1)
	{
		if (flat->MAP[(int)(Y)][(int)(X + MS * DIR_X)] == 'G')
			flat->MAP[(int)(Y)][(int)(X + MS * DIR_X)] = 48;
		if (flat->MAP[(int)(Y + MS * DIR_Y)][(int)(X)] == 'G')
			flat->MAP[(int)(Y + MS * DIR_Y)][(int)(X)] = 48;
	}
	return (1);
}

static void	ft_am(t_flat *flat)
{
	int		x;

	if (flat->MAP[(int)Y][(int)X] == 'A' && flat->map->loc.ammo < 40)
	{
		x = -1;
		ft_ammo();
		flat->map->loc.ammo += 8;
		if (flat->map->loc.ammo > 40)
			flat->map->loc.ammo = 40;
		while (++x < flat->map->sc)
			if (flat->spr[x].x == (int)X && flat->spr[x].y == (int)Y)
			{
				flat->spr[x].type = 48;
				break ;
			}
		flat->acc = 1;
		flat->MAP[(int)Y][(int)X] = 48;
	}
}

static void	ft_tp(t_flat *flat)
{
	int		x;

	if (flat->MAP[(int)Y][(int)X] == 'T')
	{
		flat->map->loc.hp -= 16;
		ft_dmg();
		x = -1;
		while (++x < flat->map->sc)
			if (flat->spr[x].x == (int)X && flat->spr[x].y == (int)Y)
			{
				flat->spr[x].type = 48;
				break ;
			}
		flat->scc = 1;
		flat->MAP[(int)Y][(int)X] = 48;
	}
}

int			ft_events0(t_flat *flat, int x, int y)
{
	ft_rat(flat, x, y);
	if (!(ft_fu(flat)))
		return (0);
	ft_am(flat);
	ft_tp(flat);
	return (1);
}
