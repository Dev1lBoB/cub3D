/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:01:23 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/08 22:47:25 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_zoomer(t_flat flat, double x, double y, int ar)
{
	double		z;
	double		p;

	p = y + 15;
	z = x + 15;
	while (++y < p)
	{
		x = z - 15;
		while (++x < z)
		{
			ft_mmpp(&flat, x, y, ar);
		}
	}
}
