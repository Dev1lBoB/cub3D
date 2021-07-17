/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:07:47 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/24 00:47:35 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

int		main(int argc, char **argv)
{
	t_flat	flat;

	flat.mlx = 0;
	flat.win = 0;
	ft_firstcheck(argc, argv, &flat);
	flat.map = ft_read(argv, flat.map, 0);
	flat.spr = malloc(sizeof(t_spr) * flat.map->sc);
	flat.map->slen = malloc(sizeof(double) * flat.map->size_x);
	ft_sprite_init(&flat);
	flat.mlx = mlx_init();
	flat.win = mlx_new_window(flat.mlx, flat.map->size_x,
	flat.map->size_y, "cub3D");
	ft_init_tx2(&flat);
	ft_music(flat.map->text_mc);
	ft_hooks(&flat);
	mlx_loop_hook(flat.mlx, &ft_movement, &flat);
	mlx_loop(flat.mlx);
}
