/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:45:41 by wpersimm          #+#    #+#             */
/*   Updated: 2020/12/23 23:29:22 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2D_H
# define FT_2D_H

# include <sys/types.h>
# include "ft_read.h"
# include "mlx.h"

typedef struct	s_ray
{
	double		cam;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		dlt_dist_x;
	double		dlt_dist_y;
	double		height;
	double		jump;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			wall;
	int			side;
}				t_ray;

typedef struct	s_text
{
	int		bpp;
	int		ll;
	int		end;
	int		h;
	int		w;
	int		x;
	double	wall;
	double	pos;
	double	step;
	void	*add;
	void	*tex;
}				t_text;

typedef struct	s_gate
{
	double	ray_dirx0;
	double	ray_diry0;
	double	ray_dirx1;
	double	ray_diry1;
	double	row_dist;
	double	f_stepx;
	double	f_stepy;
	double	floorx;
	double	floory;
	int		p;
	int		cellx;
	int		celly;
}				t_gate;

typedef struct	s_spr
{
	int		x;
	int		y;
	char	type;
	double	dist;
	int		hp;
	int		flag;
	int		fire;
}				t_spr;

typedef struct	s_stext
{
	t_text		a;
	t_text		t;
	t_text		h;
	t_text		br;
	t_text		rk;
	t_text		en;
	t_text		en2;
	t_text		en3;
}				t_stext;

typedef struct	s_flat
{
	t_map		*map;
	void		*mlx;
	void		*win;
	void		*adr;
	void		*img;
	int			ll;
	int			bpp;
	int			end;
	int			save;
	t_ray		ray;
	t_spr		*spr;
	t_stext		sprt;
	t_gate		tp;
	t_gate		bt;
	t_text		no;
	t_text		so;
	t_text		we;
	t_text		ea;
	t_text		bot;
	t_text		top;
	t_text		gun;
	t_text		gun2;
	t_text		hp[10];
	t_text		pr[11];
	t_text		am[21];
	t_text		sc[3];
	int			scc;
	int			hcc;
	int			acc;
	t_text		hd;
}				t_flat;

void			ft_firstcheck(int argc, char **argv, t_flat *flat);
void			ft_mmpp(t_flat *flat, int x, int y, int color);
void			ft_zoomer(t_flat flat, double x, double y, int ar);
void			ft_show(t_flat *flat);
void			ft_drawgates1(t_flat *flat, t_text *tex, int y, int ty);
void			ft_drawgates2(t_flat *flat, t_text *tex, int y, int ty);
void			ft_drawbot(t_flat *flat, t_text *tex);
void			ft_drawtop(t_flat *flat, t_text *tex);
void			ft_target(t_flat flat);
void			ft_gun(t_flat *flat, t_text *tex, unsigned int col);
void			ft_hb(t_flat *flat, t_text *tex, unsigned int col);
void			ft_hd(t_flat *flat, t_text *tex, unsigned int col, float a);
void			ft_ab(t_flat *flat, t_text *tex, unsigned int col);
void			ft_pb(t_flat *flat, t_text *tex, unsigned int col);
void			ft_screen(t_flat *flat, t_text *tex, unsigned int col);
void			ft_init_tx0(t_flat *flat);
void			ft_init_tx1(t_flat *flat);
void			ft_init_tx2(t_flat *flat);
void			ft_draw_spr(t_flat *flat);
void			ft_spr_text(t_text *t1, t_text *t2);
void			ft_spr_init(t_flat *flat);
void			ft_enemy_ray(t_flat *flat, int c);
void			ft_fire(t_flat *flat);
double			ft_cast_ray(t_flat *flat, int z);
void			ft_draw_line(t_flat *flat, double h, int z, t_text *tex);
int				ft_movement(t_flat *flat);
int				ft_key_release(int key, t_flat *flat);
int				ft_key_press(int key, t_flat *flat);
int				ft_click(int key, int key2, int key3, t_flat *flat);
int				ft_motion(int key1, int key2, t_flat *flat);
int				ft_exit(void);
int				ft_abs(int x);
int				ft_hooks(t_flat *flat);
void			ft_lvl(t_flat *flat);
void			ft_mv(t_flat *flat);
void			ft_turn(t_flat *flat);
int				ft_events0(t_flat *flat, int x, int y);
int				ft_funcs(t_flat *flat, int x, int y);
void			ft_create_bmp(t_flat *flat);
int				ft_get_color(int ty, t_text *tex);
void			ft_sprite_init(t_flat *flat);
void			ft_shot(void);
void			ft_death(void);
void			ft_heal(void);
void			ft_ammo(void);
void			ft_noammo(void);
void			ft_dmg(void);
void			ft_music(char *ar);
void			ft_nextlvl(void);

#endif
