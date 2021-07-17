/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:54:05 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/21 22:58:18 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_cr_c0(t_flat *flat, int z)
{
	flat->ray.cam = 2 * (z) / (double)(flat->map->size_x) - 1;
	flat->ray.ray_dir_x = DIR_X + PLAN_X * flat->ray.cam;
	flat->ray.ray_dir_y = DIR_Y + PLAN_Y * flat->ray.cam;
	flat->ray.map_x = (int)flat->map->loc.x;
	flat->ray.map_y = (int)flat->map->loc.y;
}

static void	ft_cr_c1(t_flat *flat, int z)
{
	ft_cr_c0(flat, z);
	if (flat->ray.ray_dir_y == 0)
		flat->ray.dlt_dist_x = 0;
	else
		flat->ray.dlt_dist_x = (flat->ray.ray_dir_x == 0) ? 1
		: fabs(1 / flat->ray.ray_dir_x);
	if (flat->ray.ray_dir_x == 0)
		flat->ray.dlt_dist_y = 0;
	else
		flat->ray.dlt_dist_y = (flat->ray.ray_dir_y == 0) ? 1
		: 1 / fabs(flat->ray.ray_dir_y);
	flat->ray.wall = 0;
	if (flat->ray.ray_dir_x < 0)
	{
		flat->ray.step_x = -1;
		flat->ray.side_dist_x = (flat->map->loc.x - flat->ray.map_x)
		* flat->ray.dlt_dist_x;
	}
	else
	{
		flat->ray.step_x = 1;
		flat->ray.side_dist_x = (-flat->map->loc.x + flat->ray.map_x + 1)
		* flat->ray.dlt_dist_x;
	}
}

static void	ft_cr_c2(t_flat *flat)
{
	if (flat->ray.ray_dir_y < 0)
	{
		flat->ray.step_y = -1;
		flat->ray.side_dist_y = (flat->map->loc.y - flat->ray.map_y)
		* flat->ray.dlt_dist_y;
	}
	else
	{
		flat->ray.step_y = 1;
		flat->ray.side_dist_y = (-flat->map->loc.y + flat->ray.map_y + 1)
		* flat->ray.dlt_dist_y;
	}
}

static void	ft_cr_c3(t_flat *flat)
{
	while (flat->ray.wall == 0)
	{
		if (flat->ray.side_dist_x < flat->ray.side_dist_y)
		{
			flat->ray.side_dist_x += flat->ray.dlt_dist_x;
			flat->ray.map_x += flat->ray.step_x;
			flat->ray.side = 0;
		}
		else
		{
			flat->ray.side_dist_y += flat->ray.dlt_dist_y;
			flat->ray.map_y += flat->ray.step_y;
			flat->ray.side = 1;
		}
		if (flat->MAP[flat->ray.map_y][flat->ray.map_x] == 49
		|| flat->MAP[flat->ray.map_y][flat->ray.map_x] == 'G')
			flat->ray.wall = 1;
	}
	if (flat->ray.side == 0)
		flat->ray.height = (flat->ray.map_x - flat->map->loc.x +
		(double)(1 - flat->ray.step_x) / 2) / flat->ray.ray_dir_x;
	else
		flat->ray.height = (flat->ray.map_y - flat->map->loc.y +
		(double)(1 - flat->ray.step_y) / 2) / flat->ray.ray_dir_y;
}

double		ft_cast_ray(t_flat *flat, int z)
{
	ft_cr_c1(flat, z);
	ft_cr_c2(flat);
	ft_cr_c3(flat);
	if (flat->ray.map_y >= Y && flat->ray.map_x > X)
		if (flat->ray.side == 0)
			ft_draw_line(flat, flat->ray.height, z, &flat->ea);
		else
			ft_draw_line(flat, flat->ray.height, z, &flat->so);
	else if (flat->ray.map_y < Y && flat->ray.map_x > X)
		if (flat->ray.side == 0)
			ft_draw_line(flat, flat->ray.height, z, &flat->ea);
		else
			ft_draw_line(flat, flat->ray.height, z, &flat->no);
	else if (flat->ray.map_y > Y && flat->ray.map_x <= X)
		if (flat->ray.side == 0)
			ft_draw_line(flat, flat->ray.height, z, &flat->we);
		else
			ft_draw_line(flat, flat->ray.height, z, &flat->so);
	else if (flat->ray.side == 0)
		ft_draw_line(flat, flat->ray.height, z, &flat->we);
	else
		ft_draw_line(flat, flat->ray.height, z, &flat->no);
	return (flat->ray.height);
}
