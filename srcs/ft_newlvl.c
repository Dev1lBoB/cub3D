/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:20:40 by wpersimm          #+#    #+#             */
/*   Updated: 2021/07/17 13:04:56 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_secondcheck(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (i < 5)
	{
		write(2, "Error: invalid file\n", 20);
		exit(0);
	}
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
	|| str[i - 4] != '.')
	{
		write(2, "Error: invalid file\n", 20);
		exit(0);
	}
}

static void	ft_reset2(t_flat *flat)
{
	free(flat->so.tex);
	free(flat->no.tex);
	free(flat->we.tex);
	free(flat->ea.tex);
	free(flat->bot.tex);
	free(flat->top.tex);
	free(flat->gun.tex);
	free(flat->gun2.tex);
	free(flat->spr);
	free(flat->map->text_no);
	free(flat->map->text_so);
	free(flat->map->text_we);
	free(flat->map->text_ea);
}

static void	ft_reset(t_flat *flat)
{
	int		i;

	ft_reset2(flat);
	free(flat->map->text_s);
	free(flat->map->text_en);
	free(flat->map->text_en2);
	free(flat->map->text_en3);
	free(flat->map->text_cl);
	free(flat->map->text_fl);
	free(flat->map->text_mc);
	free(flat->map->slen);
	i = 0;
	while (flat->MAP[i])
		free(flat->MAP[i++]);
	free(flat->MAP);
}

void		ft_lvl(t_flat *flat)
{
	int		x;
	int		y;

	x = flat->map->size_x;
	y = flat->map->size_y;
	ft_reset(flat);
	if (ft_strncmp(flat->map->text_nt, "none", 4) == 0)
	{
		ft_putstr_fd("Your final score is: ", 2);
		ft_putnbr_fd(flat->map->loc.fscore, 2);
		write(2, "\n", 1);
		system("killall afplay");
		exit(0);
	}
	system("killall afplay");
	ft_nextlvl();
	ft_secondcheck(flat->map->text_nt);
	flat->map = ft_read(NULL, flat->map, 1);
	flat->spr = malloc(sizeof(t_spr) * flat->map->sc);
	flat->map->slen = malloc(sizeof(double) * flat->map->size_x);
	ft_sprite_init(flat);
	ft_init_tx2(flat);
	flat->map->size_x = x;
	flat->map->size_y = y;
	ft_music(flat->map->text_mc);
}
