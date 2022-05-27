/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:25:55 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/24 21:25:49 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_color_pxl(t_img *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)color);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_lines(t_all *all, int x, int y, int color)
{
	int	i;
	int	angle;

	angle = -30;
	while (angle < 30)
	{
		i = 0;
		while (convert_pixel_to_position(all,
				x + i * sin((all->map->user_view + angle) * PI / 180),
				y + i * cos((all->map->user_view + angle) * PI / 180)) != '1')
		{
			my_mlx_pixel_put(&all->mlx_info->map,
				x + i * sin((all->map->user_view + angle) * PI / 180),
				y + i * cos((all->map->user_view + angle) * PI / 180), color);
			i++;
		}
		angle++;
	}
}

void	border(t_img *img, int x, int y, int color)
{
	int	i;

	i = -1;
	while (++i <= y)
		my_mlx_pixel_put(img, x - 1, i, color);
	i = -1;
	while (++i < y)
		my_mlx_pixel_put(img, 0, i, color);
	i = -1;
	while (++i <= x)
		my_mlx_pixel_put(img, i, y - 1, color);
	i = -1;
	while (++i < x)
		my_mlx_pixel_put(img, i, 0, color);
}

void	square(t_img *img, int x, int y, t_all *all)
{
	int	i;
	int	j;

	i = all->square->line - 1;
	while (++i <= x + all->square->line)
	{
		j = all->square->col - 1;
		while (++j <= y + all->square->col)
			my_mlx_pixel_put(img, i, j, all->square->color);
	}
}
