/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 04:19:14 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 04:20:08 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

static void	ft_t0(t_flat *flat)
{
	double	odir_x;
	double	oplan_x;

	if (flat->map->loc.turn[1] == 1 && flat->map->loc.turn[3] == 1)
	{
		odir_x = DIR_X;
		DIR_X = DIR_X * cos(-RS) - DIR_Y * sin(-RS);
		DIR_Y = odir_x * sin(-RS) + DIR_Y * cos(-RS);
		oplan_x = PLAN_X;
		PLAN_X = PLAN_X * cos(-RS) - PLAN_Y * sin(-RS);
		PLAN_Y = oplan_x * sin(-RS) + PLAN_Y * cos(-RS);
	}
	if (flat->map->loc.turn[1] != 1 && flat->map->loc.turn[3] != 1)
	{
		odir_x = DIR_X;
		DIR_X = DIR_X * cos(-MRS[1]) - DIR_Y * sin(-MRS[1]);
		DIR_Y = odir_x * sin(-MRS[1]) + DIR_Y * cos(-MRS[1]);
		oplan_x = PLAN_X;
		PLAN_X = PLAN_X * cos(-MRS[1]) - PLAN_Y * sin(-MRS[1]);
		PLAN_Y = oplan_x * sin(-MRS[1]) + PLAN_Y * cos(-MRS[1]);
	}
}

static void	ft_t1(t_flat *flat)
{
	double	odir_x;
	double	oplan_x;

	if (flat->map->loc.turn[0] != 1 && flat->map->loc.turn[2] != 1)
	{
		odir_x = DIR_X;
		DIR_X = DIR_X * cos(MRS[0]) - DIR_Y * sin(MRS[0]);
		DIR_Y = odir_x * sin(MRS[0]) + DIR_Y * cos(MRS[0]);
		oplan_x = PLAN_X;
		PLAN_X = PLAN_X * cos(MRS[0]) - PLAN_Y * sin(MRS[0]);
		PLAN_Y = oplan_x * sin(MRS[0]) + PLAN_Y * cos(MRS[0]);
	}
	if (flat->map->loc.turn[0] == 1 && flat->map->loc.turn[2] == 1)
	{
		odir_x = DIR_X;
		DIR_X = DIR_X * cos(RS) - DIR_Y * sin(RS);
		DIR_Y = odir_x * sin(RS) + DIR_Y * cos(RS);
		oplan_x = PLAN_X;
		PLAN_X = PLAN_X * cos(RS) - PLAN_Y * sin(RS);
		PLAN_Y = oplan_x * sin(RS) + PLAN_Y * cos(RS);
	}
}

void		ft_turn(t_flat *flat)
{
	ft_t0(flat);
	ft_t1(flat);
}
