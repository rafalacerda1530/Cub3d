/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:16:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/25 22:16:23 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	render(t_mlx *mlx, t_all *all)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(
			mlx->mlx_ptr, mlx->win_x, mlx->win_y, "Cub3D");
	if (create_textures_img(all))
		exiter(all, EXIT_FAILURE);
	init_view(mlx, &mlx->view, all);
	init_map(mlx, &mlx->map, all);
	draw_info(all);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, &deal_key, all);
	mlx_hook(mlx->win_ptr, 33, 1L << 2, &exiter, all);
	mlx_loop(mlx->mlx_ptr);
}
