/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:10:54 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/21 22:12:28 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_init_tex4(t_flat *flat)
{
	flat->hp[8].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health0.xpm",
	&flat->hp[8].w, &flat->hp[8].h);
	flat->hp[8].tex = mlx_get_data_addr(flat->hp[8].add, &flat->hp[8].bpp,
	&flat->hp[8].ll, &flat->hp[8].end);
	flat->hp[9].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health-.xpm",
	&flat->hp[9].w, &flat->hp[9].h);
	flat->hp[9].tex = mlx_get_data_addr(flat->hp[9].add, &flat->hp[9].bpp,
	&flat->hp[9].ll, &flat->hp[9].end);
	flat->pr[0].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress0.xpm", &flat->pr[0].w, &flat->pr[0].h);
	flat->pr[0].tex = mlx_get_data_addr(flat->pr[0].add, &flat->pr[0].bpp,
	&flat->pr[0].ll, &flat->pr[0].end);
	flat->pr[1].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress1.xpm", &flat->pr[1].w, &flat->pr[1].h);
	flat->pr[1].tex = mlx_get_data_addr(flat->pr[1].add, &flat->pr[1].bpp,
	&flat->pr[1].ll, &flat->pr[1].end);
	flat->pr[2].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress2.xpm", &flat->pr[2].w, &flat->pr[2].h);
	flat->pr[2].tex = mlx_get_data_addr(flat->pr[2].add, &flat->pr[2].bpp,
	&flat->pr[2].ll, &flat->pr[2].end);
	flat->pr[3].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress3.xpm", &flat->pr[3].w, &flat->pr[3].h);
	flat->pr[3].tex = mlx_get_data_addr(flat->pr[3].add, &flat->pr[3].bpp,
	&flat->pr[3].ll, &flat->pr[3].end);
}

static void	ft_init_tex5(t_flat *flat)
{
	flat->pr[4].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress4.xpm", &flat->pr[4].w, &flat->pr[4].h);
	flat->pr[4].tex = mlx_get_data_addr(flat->pr[4].add, &flat->pr[4].bpp,
	&flat->pr[4].ll, &flat->pr[4].end);
	flat->pr[5].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress5.xpm", &flat->pr[5].w, &flat->pr[5].h);
	flat->pr[5].tex = mlx_get_data_addr(flat->pr[5].add, &flat->pr[5].bpp,
	&flat->pr[5].ll, &flat->pr[5].end);
	flat->pr[6].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress6.xpm", &flat->pr[6].w, &flat->pr[6].h);
	flat->pr[6].tex = mlx_get_data_addr(flat->pr[6].add, &flat->pr[6].bpp,
	&flat->pr[6].ll, &flat->pr[6].end);
	flat->pr[7].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress7.xpm", &flat->pr[7].w, &flat->pr[7].h);
	flat->pr[7].tex = mlx_get_data_addr(flat->pr[7].add, &flat->pr[7].bpp,
	&flat->pr[7].ll, &flat->pr[7].end);
	flat->pr[8].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress8.xpm", &flat->pr[8].w, &flat->pr[8].h);
	flat->pr[8].tex = mlx_get_data_addr(flat->pr[8].add, &flat->pr[8].bpp,
	&flat->pr[8].ll, &flat->pr[8].end);
	flat->pr[9].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress9.xpm", &flat->pr[9].w, &flat->pr[9].h);
	flat->pr[9].tex = mlx_get_data_addr(flat->pr[9].add, &flat->pr[9].bpp,
	&flat->pr[9].ll, &flat->pr[9].end);
}

static void	ft_init_tex6(t_flat *flat)
{
	flat->pr[10].add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/progress10.xpm", &flat->pr[10].w, &flat->pr[10].h);
	flat->pr[10].tex = mlx_get_data_addr(flat->pr[10].add, &flat->pr[10].bpp,
	&flat->pr[10].ll, &flat->pr[10].end);
	flat->hd.add = mlx_xpm_file_to_image(flat->mlx, "./textures/head.xpm",
	&flat->hd.w, &flat->hd.h);
	flat->hd.tex = mlx_get_data_addr(flat->hd.add, &flat->hd.bpp, &flat->hd.ll,
	&flat->hd.end);
	flat->am[0].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO0.xpm",
	&flat->am[0].w, &flat->am[0].h);
	flat->am[0].tex = mlx_get_data_addr(flat->am[0].add, &flat->am[0].bpp,
	&flat->am[0].ll, &flat->am[0].end);
	flat->am[1].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO1.xpm",
	&flat->am[1].w, &flat->am[1].h);
	flat->am[1].tex = mlx_get_data_addr(flat->am[1].add, &flat->am[1].bpp,
	&flat->am[1].ll, &flat->am[1].end);
	flat->am[2].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO2.xpm",
	&flat->am[2].w, &flat->am[2].h);
	flat->am[2].tex = mlx_get_data_addr(flat->am[2].add, &flat->am[2].bpp,
	&flat->am[2].ll, &flat->am[2].end);
	flat->am[3].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO3.xpm",
	&flat->am[3].w, &flat->am[3].h);
	flat->am[3].tex = mlx_get_data_addr(flat->am[3].add, &flat->am[3].bpp,
	&flat->am[3].ll, &flat->am[3].end);
}

static void	ft_init_tex7(t_flat *flat)
{
	flat->am[4].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO4.xpm",
	&flat->am[4].w, &flat->am[4].h);
	flat->am[4].tex = mlx_get_data_addr(flat->am[4].add, &flat->am[4].bpp,
	&flat->am[4].ll, &flat->am[4].end);
	flat->am[5].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO5.xpm",
	&flat->am[5].w, &flat->am[5].h);
	flat->am[5].tex = mlx_get_data_addr(flat->am[5].add, &flat->am[5].bpp,
	&flat->am[5].ll, &flat->am[5].end);
	flat->am[6].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO6.xpm",
	&flat->am[6].w, &flat->am[6].h);
	flat->am[6].tex = mlx_get_data_addr(flat->am[6].add, &flat->am[6].bpp,
	&flat->am[6].ll, &flat->am[6].end);
	flat->am[7].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO7.xpm",
	&flat->am[7].w, &flat->am[7].h);
	flat->am[7].tex = mlx_get_data_addr(flat->am[7].add, &flat->am[7].bpp,
	&flat->am[7].ll, &flat->am[7].end);
	flat->am[8].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO8.xpm",
	&flat->am[8].w, &flat->am[8].h);
	flat->am[8].tex = mlx_get_data_addr(flat->am[8].add, &flat->am[8].bpp,
	&flat->am[8].ll, &flat->am[8].end);
	flat->am[9].add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO9.xpm",
	&flat->am[9].w, &flat->am[9].h);
	flat->am[9].tex = mlx_get_data_addr(flat->am[9].add, &flat->am[9].bpp,
	&flat->am[9].ll, &flat->am[9].end);
}

void		ft_init_tx1(t_flat *flat)
{
	ft_init_tex4(flat);
	ft_init_tex5(flat);
	ft_init_tex6(flat);
	ft_init_tex7(flat);
}
