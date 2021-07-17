/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:44:42 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:34:52 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_fr_c1(t_flat *flat, t_ray *ray)
{
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (Y - ray->map_y) * ray->dlt_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (-Y + ray->map_y + 1) * ray->dlt_dist_y;
	}
}

static void	ft_fr_c0(t_flat *flat, t_ray *ray)
{
	ray->map_x = X;
	ray->map_y = Y;
	ray->ray_dir_x = DIR_X;
	ray->ray_dir_y = DIR_Y;
	if (ray->ray_dir_y == 0)
		ray->dlt_dist_x = 0;
	else
		ray->dlt_dist_x = (ray->ray_dir_x == 0) ? 1 : fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_x == 0)
		ray->dlt_dist_y = 0;
	else
		ray->dlt_dist_y = (ray->ray_dir_y == 0) ? 1 : 1 / fabs(ray->ray_dir_y);
	ray->wall = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (X - ray->map_x) * ray->dlt_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (-X + ray->map_x + 1) * ray->dlt_dist_x;
	}
	ft_fr_c1(flat, ray);
}

static void	ft_fr_c2(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->dlt_dist_x;
		ray->map_x += ray->step_x;
	}
	else
	{
		ray->side_dist_y += ray->dlt_dist_y;
		ray->map_y += ray->step_y;
	}
}

static void	ft_fr_c3(t_flat *flat, t_ray *ray, int c)
{
	while (++c < flat->map->sc)
		if (ray->map_y == flat->spr[c].y && ray->map_x == flat->spr[c].x)
		{
			flat->spr[c].hp -= 8;
			if (flat->spr[c].hp <= 0)
			{
				flat->map->loc.score++;
				flat->map->loc.fscore += flat->spr[c].dist;
				flat->spr[c].type = 48;
				flat->MAP[ray->map_y][ray->map_x] = 48;
			}
		}
}

void		ft_fire(t_flat *flat)
{
	t_ray	ray;
	int		c;

	c = -1;
	ft_fr_c0(flat, &ray);
	while (ray.wall == 0)
	{
		ft_fr_c2(&ray);
		if (flat->MAP[ray.map_y][ray.map_x] == 'U' ||
		flat->MAP[ray.map_y][ray.map_x] == 'Z' || flat->spr[c].type == 'X')
		{
			ft_fr_c3(flat, &ray, c);
			break ;
		}
		if (flat->MAP[ray.map_y][ray.map_x] == 49 ||
		flat->MAP[ray.map_y][ray.map_x] == 50 ||
		flat->MAP[ray.map_y][ray.map_x] == 'G')
			ray.wall = 1;
	}
}
