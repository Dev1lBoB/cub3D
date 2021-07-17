/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:12:41 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/21 22:15:49 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_init_tex8(t_flat *flat)
{
	flat->am[10].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO10.xpm",
	&flat->am[10].w, &flat->am[10].h);
	flat->am[10].tex = mlx_get_data_addr(flat->am[10].add, &flat->am[10].bpp,
	&flat->am[10].ll, &flat->am[10].end);
	flat->am[11].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO11.xpm",
	&flat->am[11].w, &flat->am[11].h);
	flat->am[11].tex = mlx_get_data_addr(flat->am[11].add, &flat->am[11].bpp,
	&flat->am[11].ll, &flat->am[11].end);
	flat->am[12].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO12.xpm",
	&flat->am[12].w, &flat->am[12].h);
	flat->am[12].tex = mlx_get_data_addr(flat->am[12].add, &flat->am[12].bpp,
	&flat->am[12].ll, &flat->am[12].end);
	flat->am[13].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO13.xpm",
	&flat->am[13].w, &flat->am[13].h);
	flat->am[13].tex = mlx_get_data_addr(flat->am[13].add, &flat->am[13].bpp,
	&flat->am[13].ll, &flat->am[13].end);
	flat->am[14].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO14.xpm",
	&flat->am[14].w, &flat->am[14].h);
	flat->am[14].tex = mlx_get_data_addr(flat->am[14].add, &flat->am[14].bpp,
	&flat->am[14].ll, &flat->am[14].end);
	flat->am[15].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO15.xpm",
	&flat->am[15].w, &flat->am[15].h);
	flat->am[15].tex = mlx_get_data_addr(flat->am[15].add, &flat->am[15].bpp,
	&flat->am[15].ll, &flat->am[15].end);
}

static void	ft_init_tex9(t_flat *flat)
{
	flat->am[16].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO16.xpm",
	&flat->am[16].w, &flat->am[16].h);
	flat->am[16].tex = mlx_get_data_addr(flat->am[16].add, &flat->am[16].bpp,
	&flat->am[16].ll, &flat->am[16].end);
	flat->am[17].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO17.xpm",
	&flat->am[17].w, &flat->am[17].h);
	flat->am[17].tex = mlx_get_data_addr(flat->am[17].add, &flat->am[17].bpp,
	&flat->am[17].ll, &flat->am[17].end);
	flat->am[18].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO18.xpm",
	&flat->am[18].w, &flat->am[18].h);
	flat->am[18].tex = mlx_get_data_addr(flat->am[18].add, &flat->am[18].bpp,
	&flat->am[18].ll, &flat->am[18].end);
	flat->am[19].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO19.xpm",
	&flat->am[19].w, &flat->am[19].h);
	flat->am[19].tex = mlx_get_data_addr(flat->am[19].add, &flat->am[19].bpp,
	&flat->am[19].ll, &flat->am[19].end);
	flat->am[20].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO20.xpm",
	&flat->am[20].w, &flat->am[20].h);
	flat->am[20].tex = mlx_get_data_addr(flat->am[20].add, &flat->am[20].bpp,
	&flat->am[20].ll, &flat->am[20].end);
	flat->sc[0].add = mlx_xpm_file_to_image(flat->mlx, "./textures/dmg.xpm",
	&flat->sc[0].w, &flat->sc[0].h);
	flat->sc[0].tex = mlx_get_data_addr(flat->sc[0].add, &flat->sc[0].bpp,
	&flat->sc[0].ll, &flat->sc[0].end);
}

static void	ft_init_tex10(t_flat *flat)
{
	flat->sc[1].add = mlx_xpm_file_to_image(flat->mlx, "./textures/heal.xpm",
	&flat->sc[1].w, &flat->sc[1].h);
	flat->sc[1].tex = mlx_get_data_addr(flat->sc[1].add, &flat->sc[1].bpp,
	&flat->sc[1].ll, &flat->sc[1].end);
	flat->sc[2].add = mlx_xpm_file_to_image(flat->mlx, "./textures/am.xpm",
	&flat->sc[2].w, &flat->sc[2].h);
	flat->sc[2].tex = mlx_get_data_addr(flat->sc[2].add, &flat->sc[2].bpp,
	&flat->sc[2].ll, &flat->sc[2].end);
}

void		ft_init_tx2(t_flat *flat)
{
	ft_init_tx0(flat);
	ft_init_tx1(flat);
	ft_init_tex8(flat);
	ft_init_tex9(flat);
	ft_init_tex10(flat);
	flat->ray.jump = 2;
	flat->scc = 0;
	flat->hcc = 0;
	flat->acc = 0;
}
