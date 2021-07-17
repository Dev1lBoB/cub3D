/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:46:24 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/24 00:47:20 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d.h"

void	ft_dopcheck(int argc, char **argv, t_flat *flat)
{
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6 || ft_strncmp(argv[2], "--save", 6))
		{
			write(2, "Error:\nwrong 2-nd argument\n", 27);
			exit(0);
		}
		flat->save = 1;
	}
}

void	ft_firstcheck(int argc, char **argv, t_flat *flat)
{
	int		i;

	flat->save = 0;
	if (argc != 2 && argc != 3)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		exit(0);
	}
	i = ft_strlen(argv[1]);
	if (i < 5)
	{
		write(2, "Error: invalid file\n", 20);
		exit(0);
	}
	if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u' || argv[1][i - 3] != 'c'
	|| argv[1][i - 4] != '.')
	{
		write(2, "Error: invalid file\n", 20);
		exit(0);
	}
	ft_dopcheck(argc, argv, flat);
}

int		ft_hooks(t_flat *flat)
{
	mlx_hook(flat->win, 4, 0, &ft_click, flat);
	mlx_hook(flat->win, 6, 0, &ft_motion, flat);
	mlx_hook(flat->win, 3, 0, &ft_key_release, flat);
	mlx_hook(flat->win, 2, 0, &ft_key_press, flat);
	mlx_hook(flat->win, 17, 0, ft_exit, flat);
	return (0);
}
