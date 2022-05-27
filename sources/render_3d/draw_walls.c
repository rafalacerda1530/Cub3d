/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:16:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/23 19:40:42 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_wall_line(t_all *all, int i, int j, t_dot	*dot)
{
	int	buffer_pixel;

	buffer_pixel = ((j - dot->line_offset) * 64 / dot->line_hight) * 64
		+ (int)(dot->x_hit * 64);
	if (dot->wall_hit == E)
		my_mlx_pixel_put(&all->mlx_info->view, i, j,
			all->texture->e_buffer[buffer_pixel]);
	else if (dot->wall_hit == W)
		my_mlx_pixel_put(&all->mlx_info->view, i, j,
			all->texture->w_buffer[buffer_pixel]);
	else if (dot->wall_hit == N)
		my_mlx_pixel_put(&all->mlx_info->view, i, j,
			all->texture->n_buffer[buffer_pixel]);
	else if (dot->wall_hit == S)
		my_mlx_pixel_put(&all->mlx_info->view, i, j,
			all->texture->s_buffer[buffer_pixel]);
}

static void	draw_items(t_all *all, int i, t_dot	*dot)
{
	int		j;

	j = -1;
	while (++j < all->mlx_info->win_y - all->mlx_info->win_y / 3)
	{
		if (j <= dot->line_offset)
			my_mlx_pixel_put(&all->mlx_info->view, i,
				j, all->texture->c_hexa);
		else if (j > dot->line_offset && j < dot->line_hight + dot->line_offset)
			draw_wall_line(all, i, j, dot);
		else
			my_mlx_pixel_put(&all->mlx_info->view, i,
				j, all->texture->f_hexa);
	}
}

static void	get_hit_info(t_all *all, t_dot	*dot, float i, float j)
{
	float	x_offset;
	float	y_offset;

	x_offset = all->map->user_x - (int)all->map->user_x;
	y_offset = all->map->user_y - (int)all->map->user_y;
	if (dot->wall_hit == E)
		dot->x_hit = i * cos((all->map->user_view - j) * PI / 180)
			- (int)(i * cos((all->map->user_view - j) * PI / 180)) + y_offset;
	else if (dot->wall_hit == W)
		dot->x_hit = (int)(i * cos((all->map->user_view - j) * PI / 180))
			- i * cos((all->map->user_view - j) * PI / 180) - y_offset;
	else if (dot->wall_hit == N)
		dot->x_hit = i * sin((all->map->user_view - j) * PI / 180)
			- (int)(i * sin((all->map->user_view - j) * PI / 180)) + x_offset;
	else if (dot->wall_hit == S)
		dot->x_hit = (int)(i * sin((all->map->user_view - j) * PI / 180))
			- i * sin((all->map->user_view - j) * PI / 180) - x_offset;
	dot->wall_dist = i * cos(j * PI / 180);
	dot->line_hight = 400 / dot->wall_dist;
	if (dot->line_hight > 400)
		dot->line_hight = 400;
	dot->line_offset = 200 - dot->line_hight / 2;
}

static void	get_dist(t_all *all, int angle, t_dot	*dot)
{
	float	i;
	float	j;
	int		x;
	int		y;

	i = 0;
	x = all->map->user_x;
	y = all->map->user_y;
	j = ((float)angle / 15) - 30;
	while (all->map->all_map[y][x] != '1')
	{
		x = all->map->user_x + i * sin((all->map->user_view - j) * PI / 180);
		y = all->map->user_y + i * cos((all->map->user_view - j) * PI / 180);
		i += 0.01;
		if ((int)(all->map->user_x + i
			* sin((all->map->user_view - j) * PI / 180)) != x)
			set_horizontal_hit(all, j, dot);
		if ((int)(all->map->user_y + i
			* cos((all->map->user_view - j) * PI / 180)) != y)
			set_vertical_hit(all, j, dot);
	}
	get_hit_info(all, dot, i, j);
}

void	draw_walls(t_all *all)
{
	int		i;
	t_dot	dot;

	i = -1;
	while (++i < all->mlx_info->win_x)
	{
		get_dist(all, i, &dot);
		draw_items(all, i, &dot);
	}
}
