/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:08:40 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 03:02:03 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_init_tex0(t_flat *flat)
{
	flat->so.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_so,
	&flat->so.w, &flat->so.h);
	flat->so.tex = mlx_get_data_addr(flat->so.add, &flat->so.bpp, &flat->so.ll,
	&flat->so.end);
	flat->no.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_no,
	&flat->no.w, &flat->no.h);
	flat->no.tex = mlx_get_data_addr(flat->no.add, &flat->no.bpp, &flat->no.ll,
	&flat->no.end);
	flat->we.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_we,
	&flat->we.w, &flat->we.h);
	flat->we.tex = mlx_get_data_addr(flat->we.add, &flat->we.bpp, &flat->we.ll,
	&flat->we.end);
	flat->ea.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_ea,
	&flat->ea.w, &flat->ea.h);
	flat->ea.tex = mlx_get_data_addr(flat->ea.add, &flat->ea.bpp, &flat->ea.ll,
	&flat->ea.end);
	flat->bot.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_fl,
	&flat->bot.w, &flat->bot.h);
	flat->bot.tex = mlx_get_data_addr(flat->bot.add, &flat->bot.bpp,
	&flat->bot.ll, &flat->bot.end);
	flat->top.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_cl,
	&flat->top.w, &flat->top.h);
	flat->top.tex = mlx_get_data_addr(flat->top.add, &flat->top.bpp,
	&flat->top.ll, &flat->top.end);
}

static void	ft_init_tex1(t_flat *flat)
{
	flat->sprt.a.add = mlx_xpm_file_to_image(flat->mlx, "./textures/AMMO.xpm",
	&flat->sprt.a.w, &flat->sprt.a.h);
	flat->sprt.a.tex = mlx_get_data_addr(flat->sprt.a.add, &flat->sprt.a.bpp,
	&flat->sprt.a.ll, &flat->sprt.a.end);
	flat->sprt.t.add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/trap.xpm", &flat->sprt.t.w, &flat->sprt.t.h);
	flat->sprt.t.tex = mlx_get_data_addr(flat->sprt.t.add, &flat->sprt.t.bpp,
	&flat->sprt.t.ll, &flat->sprt.t.end);
	flat->sprt.en.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_en,
	&flat->sprt.en.w, &flat->sprt.en.h);
	flat->sprt.en.tex = mlx_get_data_addr(flat->sprt.en.add, &flat->sprt.en.bpp,
	&flat->sprt.en.ll, &flat->sprt.en.end);
	flat->sprt.en2.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_en2,
	&flat->sprt.en2.w, &flat->sprt.en2.h);
	flat->sprt.en2.tex = mlx_get_data_addr(flat->sprt.en2.add,
	&flat->sprt.en2.bpp, &flat->sprt.en2.ll, &flat->sprt.en2.end);
	flat->sprt.en3.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_en3,
	&flat->sprt.en3.w, &flat->sprt.en3.h);
	flat->sprt.en3.tex = mlx_get_data_addr(flat->sprt.en3.add,
	&flat->sprt.en3.bpp, &flat->sprt.en3.ll, &flat->sprt.en3.end);
	flat->sprt.h.add = mlx_xpm_file_to_image(flat->mlx, "./textures/MEDI.xpm",
	&flat->sprt.h.w, &flat->sprt.h.h);
	flat->sprt.h.tex = mlx_get_data_addr(flat->sprt.h.add, &flat->sprt.h.bpp,
	&flat->sprt.h.ll, &flat->sprt.h.end);
}

static void	ft_init_tex2(t_flat *flat)
{
	flat->sprt.br.add = mlx_xpm_file_to_image(flat->mlx, flat->map->text_s,
	&flat->sprt.br.w, &flat->sprt.br.h);
	flat->sprt.br.tex = mlx_get_data_addr(flat->sprt.br.add, &flat->sprt.br.bpp,
	&flat->sprt.br.ll, &flat->sprt.br.end);
	flat->sprt.rk.add = mlx_xpm_file_to_image(flat->mlx,
	"./textures/pillar.xpm", &flat->sprt.rk.w, &flat->sprt.rk.h);
	flat->sprt.rk.tex = mlx_get_data_addr(flat->sprt.rk.add, &flat->sprt.rk.bpp,
	&flat->sprt.rk.ll, &flat->sprt.rk.end);
	flat->gun.add = mlx_xpm_file_to_image(flat->mlx, "./textures/gun2.xpm",
	&flat->gun.w, &flat->gun.h);
	flat->gun.tex = mlx_get_data_addr(flat->gun.add, &flat->gun.bpp,
	&flat->gun.ll, &flat->gun.end);
	flat->gun2.add = mlx_xpm_file_to_image(flat->mlx, "./textures/image.xpm",
	&flat->gun2.w, &flat->gun2.h);
	flat->gun2.tex = mlx_get_data_addr(flat->gun2.add, &flat->gun2.bpp,
	&flat->gun2.ll, &flat->gun2.end);
	flat->hp[0].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health1.xpm",
	&flat->hp[0].w, &flat->hp[0].h);
	flat->hp[0].tex = mlx_get_data_addr(flat->hp[0].add, &flat->hp[0].bpp,
	&flat->hp[0].ll, &flat->hp[0].end);
	flat->hp[1].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health2.xpm",
	&flat->hp[1].w, &flat->hp[1].h);
	flat->hp[1].tex = mlx_get_data_addr(flat->hp[1].add, &flat->hp[1].bpp,
	&flat->hp[1].ll, &flat->hp[1].end);
}

static void	ft_init_tex3(t_flat *flat)
{
	flat->hp[2].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health3.xpm",
	&flat->hp[2].w, &flat->hp[2].h);
	flat->hp[2].tex = mlx_get_data_addr(flat->hp[2].add, &flat->hp[2].bpp,
	&flat->hp[2].ll, &flat->hp[2].end);
	flat->hp[3].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health4.xpm",
	&flat->hp[3].w, &flat->hp[3].h);
	flat->hp[3].tex = mlx_get_data_addr(flat->hp[3].add, &flat->hp[3].bpp,
	&flat->hp[3].ll, &flat->hp[3].end);
	flat->hp[4].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health5.xpm",
	&flat->hp[4].w, &flat->hp[4].h);
	flat->hp[4].tex = mlx_get_data_addr(flat->hp[4].add, &flat->hp[4].bpp,
	&flat->hp[4].ll, &flat->hp[4].end);
	flat->hp[5].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health6.xpm",
	&flat->hp[5].w, &flat->hp[5].h);
	flat->hp[5].tex = mlx_get_data_addr(flat->hp[5].add, &flat->hp[5].bpp,
	&flat->hp[5].ll, &flat->hp[5].end);
	flat->hp[6].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health7.xpm",
	&flat->hp[6].w, &flat->hp[6].h);
	flat->hp[6].tex = mlx_get_data_addr(flat->hp[6].add, &flat->hp[6].bpp,
	&flat->hp[6].ll, &flat->hp[6].end);
	flat->hp[7].add = mlx_xpm_file_to_image(flat->mlx, "./textures/health8.xpm",
	&flat->hp[7].w, &flat->hp[7].h);
	flat->hp[7].tex = mlx_get_data_addr(flat->hp[7].add, &flat->hp[7].bpp,
	&flat->hp[7].ll, &flat->hp[7].end);
}

void		ft_init_tx0(t_flat *flat)
{
	ft_init_tex0(flat);
	ft_init_tex1(flat);
	ft_init_tex2(flat);
	ft_init_tex3(flat);
}
