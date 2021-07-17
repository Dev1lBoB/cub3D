/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 01:20:09 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:34:22 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_er_c0(t_flat *flat, t_ray *ray, int c)
{
	double	line;

	ray->map_x = (int)flat->spr[c].x;
	ray->map_y = (int)flat->spr[c].y;
	line = sqrt(pow(ray->map_x - X, 2) + pow(ray->map_y - Y, 2));
	ray->ray_dir_x = -(ray->map_x - X) / line;
	ray->ray_dir_y = -(ray->map_y - Y) / line;
}

static void	ft_er_c1(t_flat *flat, t_ray *ray, int c)
{
	ft_er_c0(flat, ray, c);
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
		ray->side_dist_x = (flat->spr[c].x - ray->map_x) * ray->dlt_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (-flat->spr[c].x + ray->map_x + 1) * ray->dlt_dist_x;
	}
}

static void	ft_er_c2(t_flat *flat, t_ray *ray, int c)
{
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (flat->spr[c].y - ray->map_y) * ray->dlt_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (-flat->spr[c].y + ray->map_y + 1) * ray->dlt_dist_y;
	}
}

static void	ft_er_c3(t_ray *ray)
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

void		ft_enemy_ray(t_flat *flat, int c)
{
	t_ray	ray;

	ft_er_c1(flat, &ray, c);
	ft_er_c2(flat, &ray, c);
	while (ray.wall == 0)
	{
		ft_er_c3(&ray);
		if (ray.map_x == (int)X && ray.map_y == (int)Y)
		{
			flat->spr[c].type = 'Z';
			flat->spr[c].flag = 1;
			break ;
		}
		else
		{
			flat->spr[c].type = 'U';
			flat->spr[c].flag = 0;
		}
		if (flat->MAP[ray.map_y][ray.map_x] == 49 ||
flat->MAP[ray.map_y][ray.map_x] == 50 || flat->MAP[ray.map_y][ray.map_x] == 'G')
			ray.wall = 1;
	}
}
