/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:20:55 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/24 02:29:22 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# define MAP map->map
# define Y flat->map->loc.y
# define X flat->map->loc.x
# define DIR_X flat->map->loc.dir_x
# define DIR_Y flat->map->loc.dir_y
# define PLAN_X flat->map->loc.plan_x
# define PLAN_Y flat->map->loc.plan_y
# define MS (double)0.2
# define RS (double)M_PI/90
# define MRS 0.01/M_PI*flat->map->loc.turn
# define URS 0.01*flat->map->loc.look
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct		s_loc
{
	double		x;
	double		y;
	int			x_s;
	int			y_s;
	double		dir;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	int			pause;
	int			use;
	int			ammo;
	int			fire;
	int			hp;
	int			life;
	int			jump;
	int			walk[4];
	int			turn[4];
	int			look;
	int			score;
	int			fscore;
	int			lvl;
}					t_loc;

typedef struct		s_map
{
	int				size_x;
	int				size_y;
	char			*text_so;
	char			*text_no;
	char			*text_we;
	char			*text_ea;
	char			*text_nt;
	char			*text_mc;
	char			*text_s;
	char			*text_cl;
	char			*text_fl;
	char			*text_en;
	char			*text_en2;
	char			*text_en3;
	int				floor[3];
	int				ceilling[3];
	t_loc			loc;
	double			*slen;
	int				sc;
	int				ec;
	char			**map;
}					t_map;

t_map				*ft_read(char **argv, t_map *map, int a);
void				ft_errormap(char **line, int fd, t_map *map);
void				ft_strcheck(char *line, int fd, char **str, t_map *map);
void				ft_size(t_map *map, int fd, char **line);
void				ft_close(int fd);
void				ft_walls(t_map *map, int fd, char **loin);
void				ft_sprite(t_map *map, int fd, char **loin);
void				ft_floor(t_map *map, char *line, char **str, int fd);
void				ft_ceilling(t_map *map, char *line, char **str, int fd);
void				ft_colors(t_map *map, int fd, char **loin);
void				ft_maze(t_map *map, int fd);
void				ft_start(t_map *map);
void				ft_size_check(t_map *map);
void				ft_finish(t_map *map);
void				ft_sfinish(t_map *map);
void				ft_errormap2(int fd, t_map *map);
void				ft_validdata(t_map *map, int fd);
void				ft_void(void *lst);
void				ft_data(t_map *map, int fd, int i);
void				ft_location(t_map *map, int i, int j);
int					ft_line(int fd, char **line);
int					ft_malerr(char **line, t_map *map);
int					ft_news(t_map *map, int *br, char *news, char **line);
int					ft_novosty(char *news, char *line, int *br);
int					ft_ismap(char a);
int					ft_isspr(char a);
int					ft_bolshoe_uslovie(t_map *map, int i, int j);
int					ft_bolshoe_uslovie2(char *line, int j);
int					ft_wrong_symbol(t_map *map);
int					ft_validmap(t_map *map);

#endif
