/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:23:35 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/22 02:37:56 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_sprite_init(t_flat *flat)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	c = 0;
	while (flat->MAP[++i])
	{
		j = -1;
		while (flat->MAP[i][++j])
		{
			if (ft_isspr(flat->MAP[i][j]))
			{
				flat->spr[c].x = j;
				flat->spr[c].y = i;
				flat->spr[c].hp = 24;
				flat->spr[c].flag = 0;
				flat->spr[c].fire = 0;
				flat->spr[c++].type = flat->MAP[i][j];
			}
		}
	}
}

void	ft_spr_text(t_text *t1, t_text *t2)
{
	t1->w = t2->w;
	t1->bpp = t2->bpp;
	t1->ll = t2->ll;
	t1->end = t2->end;
	t1->h = t2->h;
	t1->tex = t2->tex;
}
