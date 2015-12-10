/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 18:11:38 by tdieumeg          #+#    #+#             */
/*   Updated: 2014/01/19 19:28:54 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				WOLF3D_H
# define			WOLF3D_H

# include			"libft.h"
# include			<math.h>
# include			<fcntl.h>
# include			<stdio.h>
# include			<mlx.h>
# define			FOV 60
# define			ZOOM 277
# define			BLOCK 256
# define			W_SIZE_X 1280
# define			W_SIZE_Y 800
# define			RAD(degree) ((M_PI * degree) / 180)
# define			IS_UP(rad) (rad > 0 && rad < M_PI)
# define			IS_DOWN(rad) (!IS_UP(rad))
# define			IS_RIGHT(rad) (rad < M_PI_2 || rad > 3 * M_PI_2)
# define			IS_LEFT(rad) (!IS_RIGHT(rad))
# define			UP_ARROW 126
# define			DOWN_ARROW 125
# define			RIGHT_ARROW 124
# define			LEFT_ARROW 123
# define			ESCAPE 53

typedef struct		s_mylist
{
	char			**content;
	size_t			content_size;
	struct s_mylist	*next;
}					t_mylist;

typedef struct		s_cd
{
	char			is_wall;
}					t_cd;

typedef struct		s_player
{
	float			x;
	float			y;
	float			pov;
}					t_player;

typedef struct		s_img
{
	void			*mlx_img;
	int				height;
	int				width;
	int				bpp;
	int				size_line;
	int				endian;
	char			*data;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_cd			***matrix;
	t_img			*img;
	t_player		*player;
}					t_env;

/*
** ft_create_matrix.c
*/
t_cd				***ft_create_matrix(t_mylist *save);

/*
** get_next_line.c
*/
int					get_next_line(int fd, char **line);

/*
** ft_functions.c
*/
float				ft_rad(float rad);
float				ft_abs(float nb);
int					ft_size_of(char **split);
int					ft_save_size(t_mylist *save);
void            	ft_lpbptr(t_mylist **list, char **content,
								size_t content_size);

/*
** ft_img_fun.c
*/
int					ft_get_pixel(t_img *wall, int x, int y);
t_img				*ft_img_init(void *mlx_ptr, int height, int width);
t_img				*ft_get_img(void *mlx_ptr, char *file_name);
void				ft_pixel_put(t_img *img, int x, int y, int color);

/*
** ft_wolf3d.c
*/
void				ft_wolf3d(t_cd ***matrix);

/*
** ft_raycast.c
*/
int					ft_outside_map(t_cd ***matrix, float x, float y);
float				ft_raycast(t_cd ***matrix, t_player *player, float rad,
								int *offset);

/*
** ft_player_fun.c
*/
t_player			*ft_place_player(t_cd ***matrix);

/*
** ft_can_move.c
*/
int					ft_can_move(t_env *env, const float x, const float y);

#endif				/* !WOLF3D_H */
