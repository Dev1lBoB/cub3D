/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:01:15 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/21 02:02:15 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_shot(void)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		system("afplay sound/shot.wav");
		exit(0);
	}
}

void	ft_death(void)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		system("afplay sound/death.mp3");
		exit(0);
	}
}

void	ft_heal(void)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		system("afplay sound/heal.mp3");
		exit(0);
	}
}

void	ft_ammo(void)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		system("afplay sound/ammo.mp3");
		exit(0);
	}
}

void	ft_nextlvl(void)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		system("afplay sound/nextlvl.mp3");
		exit(0);
	}
}
