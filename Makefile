# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 21:59:35 by wpersimm          #+#    #+#              #
#    Updated: 2020/12/24 00:57:48 by wpersimm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRCS1	= ./srcs/ft_data.c ./srcs/ft_data_2.c ./srcs/ft_errors.c \
		  ./srcs/ft_map.c ./srcs/ft_map2.c \
		  ./srcs/ft_news.c ./srcs/ft_read.c ./srcs/ft_small.c \
		  ./srcs/ft_small2.c ./srcs/ft_validdata.c


SRCS2	= ./srcs/ft_bmp.c ./srcs/ft_hud.c ./srcs/ft_render.c \
		  ./srcs/ft_cast_ray.c ./srcs/ft_init_tex0.c \
		  ./srcs/ft_show1.c ./srcs/ft_init_tex1.c \
		  ./srcs/ft_show2.c ./srcs/ft_init_tex2.c \
		  ./srcs/ft_show3.c ./srcs/ft_draw_sprite.c \
		  ./srcs/ft_enemy_ray.c ./srcs/ft_minimap.c \
		  ./srcs/ft_sounds.c ./srcs/ft_events0.c \
		  ./srcs/ft_mv.c ./srcs/ft_sounds2.c ./srcs/ft_events1.c \
		  ./srcs/ft_newlvl.c ./srcs/ft_sprite.c ./srcs/ft_fire.c \
		  ./srcs/ft_turn.c ./srcs/ft_hooks.c ./srcs/ft_main.c


SRCSL	= ./srcs/libft/ft_memset.c ./srcs/libft/ft_bzero.c \
		  ./srcs/libft/ft_memcpy.c ./srcs/libft/ft_memccpy.c \
		  ./srcs/libft/ft_memmove.c \
		  ./srcs/libft/ft_memchr.c ./srcs/libft/ft_memcmp.c \
		  ./srcs/libft/ft_strlen.c ./srcs/libft/ft_strlcpy.c \
		  ./srcs/libft/ft_strlcat.c \
		  ./srcs/libft/ft_strchr.c ./srcs/libft/ft_strrchr.c \
		  ./srcs/libft/ft_strnstr.c ./srcs/libft/ft_strncmp.c \
		  ./srcs/libft/ft_atoi.c \
		  ./srcs/libft/ft_isalpha.c ./srcs/libft/ft_isdigit.c \
		  ./srcs/libft/ft_isalnum.c ./srcs/libft/ft_isascii.c \
		  ./srcs/libft/ft_isprint.c \
		  ./srcs/libft/ft_toupper.c ./srcs/libft/ft_tolower.c \
		  ./srcs/libft/ft_calloc.c ./srcs/libft/ft_strdup.c \
		  ./srcs/libft/ft_substr.c \
		  ./srcs/libft/ft_strjoin.c ./srcs/libft/ft_strtrim.c \
		  ./srcs/libft/ft_split.c ./srcs/libft/ft_itoa.c \
		  ./srcs/libft/ft_strmapi.c \
		  ./srcs/libft/ft_putchar_fd.c ./srcs/libft/ft_putstr_fd.c \
		  ./srcs/libft/ft_putendl_fd.c ./srcs/libft/ft_putnbr_fd.c

OBJSL	= ${SRCSL:.c=.o}

HEADL	= ./srcs/libft/libft.h

LIBA	= ./srcs/libft/libft.a

SRCSG	= ./srcs/get_next_line/get_next_line.c \
		  ./srcs/get_next_line/get_next_line_utils.c

HEADG	= ./includes/get_next_line.h

SRCSM	= ./srcs/minilibx_opengl_20191021/font.c \
		  ./srcs/minilibx_opengl_20191021/mlx_rgb.c \
		  ./srcs/minilibx_opengl_20191021/mlx_int_str_to_wordtab.c \
		  ./srcs/minilibx_opengl_20191021/mlx_shaders.c \
		  ./srcs/minilibx_opengl_20191021/mlx_png.c mlx_xpm.c

OBJSM	= ${SRCSM:.c=.o}

HEADM	= ./includes/mlx.h

LIBM	= ./srcs/minilibx_opengl_20191021/libmlx.a

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -Iincludes

FLAGS2	= -framework OpenGL -framework Appkit

all:	${NAME}

${NAME}: ${LIBA} ${LIBM} ${SRCS1} ${SRCS2} ${SRCSG}
		 ${GCC} ${FLAGS} ${SRCS1} ${SRCS2} ${SRCSG} ./srcs/main.c ${LIBA} ${LIBM} -o ${NAME} ${FLAGS2}

${LIBA}: ${HEADL} ${OBJSL}
		 make -C ./srcs/libft

${LIBM}:
		 make -C ./srcs/minilibx_opengl_20191021

clean:
		make fclean -C srcs/libft
		make clean -C srcs/minilibx_opengl_20191021

fclean: clean
		rm -rf ${NAME}

re:		fclean all
