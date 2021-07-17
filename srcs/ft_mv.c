/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:13:58 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 04:16:25 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_mv0(t_flat *flat)
{
	if (flat->map->loc.walk[0] == 1)
	{
		if ((flat->MAP[(int)(Y)][(int)(X + MS * DIR_X)] != 49) &&
		flat->MAP[(int)(Y)][(int)(X + MS * DIR_X)] != 50 &&
		flat->MAP[(int)(Y)][(int)(X + MS * DIR_X)] != 'U' &&
		flat->MAP[(int)(Y)][(int)(X + MS * DIR_X)] != 'G')
			X += MS * DIR_X;
		if ((flat->MAP[(int)(Y + MS * DIR_Y)][(int)(X)] != 49) &&
		flat->MAP[(int)(Y + MS * DIR_Y)][(int)(X)] != 50 &&
		flat->MAP[(int)(Y + MS * DIR_Y)][(int)(X)] != 'U' &&
		flat->MAP[(int)(Y + MS * DIR_Y)][(int)(X)] != 'G')
			Y += MS * DIR_Y;
	}
}

static void	ft_mv1(t_flat *flat)
{
	if (flat->map->loc.walk[1] == 1)
	{
		if ((flat->MAP[(int)(Y)][(int)(X - MS * DIR_X)] != 49) &&
		flat->MAP[(int)(Y)][(int)(X - MS * DIR_X)] != 50 &&
		flat->MAP[(int)(Y)][(int)(X - MS * DIR_X)] != 'U' &&
		flat->MAP[(int)(Y)][(int)(X - MS * DIR_X)] != 'G')
			X -= MS * DIR_X;
		if ((flat->MAP[(int)(Y - MS * DIR_Y)][(int)(X)] != 49) &&
		flat->MAP[(int)(Y - MS * DIR_Y)][(int)(X)] != 50 &&
		flat->MAP[(int)(Y - MS * DIR_Y)][(int)(X)] != 'U' &&
		flat->MAP[(int)(Y - MS * DIR_Y)][(int)(X)] != 'G')
			Y -= MS * DIR_Y;
	}
}

static void	ft_mv2(t_flat *flat)
{
	if (flat->map->loc.walk[2] == 1)
	{
		if ((flat->MAP[(int)(Y)][(int)(X - MS * PLAN_X)] != 49) &&
		flat->MAP[(int)(Y)][(int)(X - MS * PLAN_X)] != 50 &&
		flat->MAP[(int)(Y)][(int)(X - MS * PLAN_X)] != 'U' &&
		flat->MAP[(int)(Y)][(int)(X - MS * PLAN_X)] != 'G')
			X -= MS * PLAN_X;
		if ((flat->MAP[(int)(Y - MS * PLAN_Y)][(int)(X)] != 49) &&
		flat->MAP[(int)(Y - MS * PLAN_Y)][(int)(X)] != 50 &&
		flat->MAP[(int)(Y - MS * PLAN_Y)][(int)(X)] != 'U' &&
		flat->MAP[(int)(Y - MS * PLAN_Y)][(int)(X)] != 'G')
			Y -= MS * PLAN_Y;
	}
}

static void	ft_mv3(t_flat *flat)
{
	if (flat->map->loc.walk[3] == 1)
	{
		if ((flat->MAP[(int)(Y)][(int)(X + MS * PLAN_X)] != 49) &&
		flat->MAP[(int)(Y)][(int)(X + MS * PLAN_X)] != 50 &&
		flat->MAP[(int)(Y)][(int)(X + MS * PLAN_X)] != 'U' &&
		flat->MAP[(int)(Y)][(int)(X + MS * PLAN_X)] != 'G')
			X += MS * PLAN_X;
		if ((flat->MAP[(int)(Y + MS * PLAN_Y)][(int)(X)] != 49) &&
		flat->MAP[(int)(Y + MS * PLAN_Y)][(int)(X)] != 50 &&
		flat->MAP[(int)(Y + MS * PLAN_Y)][(int)(X)] != 'U' &&
		flat->MAP[(int)(Y + MS * PLAN_Y)][(int)(X)] != 'G')
			Y += MS * PLAN_Y;
	}
}

void		ft_mv(t_flat *flat)
{
	ft_mv0(flat);
	ft_mv1(flat);
	ft_mv2(flat);
	ft_mv3(flat);
}
