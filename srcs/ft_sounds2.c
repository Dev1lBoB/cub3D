/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sounds2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 02:04:26 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/22 02:30:09 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_music(char *ar)
{
	char	*ar2;
	char	*ar3;

	if (!(ar2 = ft_strjoin("bash ", ar)))
	{
		system("killall afplay");
		write(2, "Error:\nMalloc abort\n", 20);
		exit(0);
	}
	if (!(ar3 = ft_strjoin(ar2, ".sh")))
	{
		system("killall afplay");
		write(2, "Error:\nMalloc abort\n", 20);
		exit(0);
	}
	free(ar2);
	system(ar3);
	free(ar3);
}

void	ft_dmg(void)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		system("afplay sound/dmg.mp3");
		exit(0);
	}
}

void	ft_noammo(void)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		system("afplay sound/noammo.mp3");
		exit(0);
	}
}
