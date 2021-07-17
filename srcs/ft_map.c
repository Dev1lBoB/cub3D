/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:10:52 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:22:25 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

void	ft_void(void *lst)
{
	(void)lst;
}

int		ft_construct(t_map *map, t_list **list, int fd, char **line)
{
	t_list	*new;
	int		i;

	while ((i = get_next_line(fd, line)) != 2)
	{
		if (i == -1)
			ft_malerr(line, map);
		if (!*line[0])
		{
			ft_lstclear(list, free);
			return (0);
		}
		if (!(new = ft_lstnew(*line)))
			ft_malerr(line, map);
		ft_lstadd_back(list, new);
		if (i == 0)
			break ;
	}
	return (1);
}

void	ft_maze(t_map *map, int fd)
{
	char	*line;
	t_list	*list;
	t_list	*list2;
	int		i;

	list = NULL;
	if (!(ft_line(fd, &line)))
		ft_malerr(&line, map);
	ft_lstadd_back(&list, ft_lstnew(line));
	if (!(ft_construct(map, &list, fd, &line)))
		ft_errormap(&line, fd, map);
	i = ft_lstsize(list);
	if (!(MAP = malloc((i + 1) * sizeof(char *))))
		ft_malerr(&line, map);
	list2 = list;
	i = 0;
	while (list2)
	{
		MAP[i++] = list2->content;
		list2 = list2->next;
	}
	MAP[i] = NULL;
	ft_lstclear(&list, ft_void);
}

void	ft_location(t_map *map, int i, int j)
{
	map->loc.x = j + 0.5;
	map->loc.y = i + 0.5;
	if (MAP[i][j] == 'W')
		map->loc.dir = M_PI / 2;
	else if (MAP[i][j] == 'E')
		map->loc.dir = 3 * M_PI / 2;
	else if (MAP[i][j] == 'N')
		map->loc.dir = M_PI;
	else if (MAP[i][j] == 'S')
		map->loc.dir = 0;
}
