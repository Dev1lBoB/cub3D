/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:46:38 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 21:54:34 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_mmpp(t_flat *flat, int x, int y, int color)
{
	char *ar;

	ar = flat->adr + (y * flat->ll + x * (flat->bpp / 8));
	*(unsigned int *)ar = color;
}

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int		ft_get_color(int text_y, t_text *tex)
{
	int		a;
	int		c;
	int		color;

	if (text_y < 0)
		text_y = 0;
	if (tex->x < 0)
		tex->x = 0;
	a = tex->ll * text_y;
	c = tex->x * (tex->bpp / 8);
	color = (*(int *)(tex->tex + a + c));
	return (color);
}

/*
** bot = 0
** top = 1
** len = 2
** text_y = 3
*/

void	ft_draw_line(t_flat *flat, double h, int z, t_text *tex)
{
	int		it[4];

	it[2] = (int)(flat->map->size_y / fabs(h));
	it[0] = (-it[2] / 2 + flat->map->size_y / flat->ray.jump);
	it[1] = (it[2] / 2 + flat->map->size_y / flat->ray.jump);
	it[0] < 0 ? it[0] = 0 : 0;
	it[1] >= flat->map->size_y ? it[1] = flat->map->size_y - 1 : 0;
	tex->wall = flat->ray.side == 0 ? Y + h * flat->ray.ray_dir_y :
	X + h * flat->ray.ray_dir_x;
	tex->wall -= floor(tex->wall);
	tex->x = (int)(tex->wall * tex->w);
	flat->ray.side == 0 && flat->ray.ray_dir_x > 0 ?
	tex->x = tex->w - tex->x - 1 : 0;
	flat->ray.side == 1 && flat->ray.ray_dir_y < 0 ?
	tex->x = tex->w - tex->x - 1 : 0;
	tex->step = 1.0 * tex->h / it[2];
	tex->pos = (it[0] - flat->map->size_y / flat->ray.jump + it[2] / 2)
	* tex->step;
	while (it[0] < it[1])
	{
		it[3] = (int)tex->pos & (tex->h - 1);
		tex->pos += tex->step;
		ft_mmpp(flat, z, it[0], ft_get_color(it[3], tex));
		it[0]++;
	}
}

int		ft_movement(t_flat *flat)
{
	int		x;
	int		y;

	ft_mv(flat);
	mlx_mouse_get_pos(flat->win, &x, &y);
	if (!(ft_funcs(flat, x, y)))
		return (0);
	flat->img = mlx_new_image(flat->mlx, flat->map->size_x, flat->map->size_y);
	flat->adr = mlx_get_data_addr(flat->img, &flat->bpp, &flat->ll, &flat->end);
	ft_show(flat);
	if (flat->map->loc.fire == 1)
	{
		ft_shot();
		flat->ray.jump += 0.15;
	}
	flat->map->loc.fire = 0;
	mlx_destroy_image(flat->mlx, flat->img);
	return (1);
}
