/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:13:46 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/26 19:10:08 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	float	user_x;
	float	user_y;
	int		user_view;
	int		quant_line;
	int		quant_max_col;
	char	**all_map;
}				t_map;

typedef struct s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_img;

typedef struct s_texture
{
	char			*n;
	char			*w;
	char			*e;
	char			*s;
	char			*f;
	char			*c;
	int				c_hexa;
	int				f_hexa;
	t_img			n_img;
	t_img			w_img;
	t_img			e_img;
	t_img			s_img;
	__uint32_t		*n_buffer;
	__uint32_t		*w_buffer;
	__uint32_t		*e_buffer;
	__uint32_t		*s_buffer;
}				t_texture;

typedef struct s_mlx {
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		view;
	t_img		map;
}				t_mlx;

typedef struct s_square
{
	int	color;
	int	line;
	int	col;
}				t_square;

typedef struct s_all
{
	t_mlx		*mlx_info;
	t_map		*map;
	t_texture	*texture;
	t_square	*square;
}				t_all;

typedef struct s_dot
{
	float	wall_dist;
	int		line_hight;
	int		line_offset;
	float	x_hit;
	int		wall_hit;
}				t_dot;

enum	e_directions
{
	N = 180,
	W = 270,
	E = 90,
	S = 0,
};

# define KSPACE 32
# define KLESS 45
# define KMORE 61
# define KESC 65307
# define KLEFT 97
# define KARROWLEFT 65361
# define KUP 119
# define KARROWUP 65362
# define KRIGHT 100
# define KARROWRIGHT 65363
# define KDOWN 115
# define KARROWDOWN 65364
# define PI 3.141592

// MAP
int						find_map(t_all *all, int argc, char *argv);
void					move_up(t_all *all);
void					move_down(t_all *all);
void					move_left(t_all *all);
void					move_right(t_all *all);

// PARSER
void					parse_map(t_all *all, int fd1);
int						populate_map_var(t_map *map, int fd1);
int						validate_map_struct(t_map *map);
int						create_textures_img(t_all *all);
void					get_textures(t_all *all, char *line);

// UTILS
int						exiter(t_all *all, int exit_number);
void					ft_free(t_all *all);
char					convert_pixel_to_position(t_all *all,
							int pixel_x, int pixel_y);
void					rgb_to_decimal(t_all *all);

// DRAW
void					border(t_img *img, int x, int y, int color);
void					render(t_mlx *mlx, t_all *all);
void					init_view(t_mlx *mlx, t_img *img, t_all *all);
void					init_map(t_mlx *mlx, t_img *img, t_all *all);
void					square(t_img *img, int x, int y, t_all *all);
int						deal_key(int key, t_all *all);
void					draw_user(t_mlx *mlx, t_img *img, t_all *all);
void					draw_lines(t_all *all, int x, int y, int color);
void					rotate(t_all *all, int signal);
void					my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int			get_color_pxl(t_img *img, int x, int y);
void					draw_info(t_all *all);

// RENDER 3D
void					draw_walls(t_all *all);
void					set_horizontal_hit(t_all *all, int j, t_dot *dot);
void					set_vertical_hit(t_all *all, int j, t_dot *dot);

#endif
