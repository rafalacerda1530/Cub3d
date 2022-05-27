/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:17:31 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/25 18:58:11 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_view(t_mlx *mlx, t_img *img, t_all *all)
{
	img->img = mlx_new_image(mlx->mlx_ptr, mlx->win_x,
			mlx->win_y - mlx->win_y / 3);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_walls(all);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img->img);
}
