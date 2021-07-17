/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:45:03 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:35:42 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

int		ft_key_release(int key, t_flat *flat)
{
	if (key == 13)
		flat->map->loc.walk[0] = 0;
	if (key == 1)
		flat->map->loc.walk[1] = 0;
	if (key == 0)
		flat->map->loc.walk[2] = 0;
	if (key == 2)
		flat->map->loc.walk[3] = 0;
	if (key == 123)
		flat->map->loc.turn[3] = 0;
	if (key == 124)
		flat->map->loc.turn[2] = 0;
	if (key == 35)
		flat->map->loc.pause = flat->map->loc.pause == 0 ? 1 : 0;
	if (key == 14)
		flat->map->loc.use = 0;
	return (0);
}

int		ft_key_press(int key, t_flat *flat)
{
	if (key == 13)
		flat->map->loc.walk[0] = 1;
	if (key == 1)
		flat->map->loc.walk[1] = 1;
	if (key == 0)
		flat->map->loc.walk[2] = 1;
	if (key == 2)
		flat->map->loc.walk[3] = 1;
	if (key == 123)
		flat->map->loc.turn[3] = 1;
	if (key == 124)
		flat->map->loc.turn[2] = 1;
	if (key == 14)
		flat->map->loc.use = 1;
	if (key == 53)
	{
		system("killall afplay");
		exit(0);
	}
	return (0);
}

int		ft_exit(void)
{
	system("killall afplay");
	exit(0);
}

int		ft_motion(int key1, int key2, t_flat *flat)
{
	if (flat->map->loc.pause != 1)
	{
		if (key1 > flat->map->size_x / 2)
		{
			flat->map->loc.turn[0] = key1 - flat->map->size_x / 2;
			flat->map->loc.turn[1] = 1;
		}
		if (key1 < flat->map->size_x / 2)
		{
			flat->map->loc.turn[1] = -key1 + flat->map->size_x / 2;
			flat->map->loc.turn[0] = 1;
		}
		if (key2 > flat->map->size_y / 2 || key2 < flat->map->size_y / 2)
		{
			flat->map->loc.look = key2 - flat->map->size_y / 2;
		}
	}
	return (0);
}

int		ft_click(int key, int key2, int key3, t_flat *flat)
{
	(void)key2;
	(void)key3;
	if (key == 1)
	{
		if (flat->map->loc.ammo != 0)
		{
			flat->map->loc.ammo--;
			flat->map->loc.fire = 1;
		}
		else
			ft_noammo();
	}
	return (0);
}
