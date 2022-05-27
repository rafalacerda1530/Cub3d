/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pixel_to_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:16:15 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/09 21:29:43 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	convert_pixel_to_position(t_all *all, int pixel_x, int pixel_y)
{
	int	map_win_x;
	int	map_win_y;
	int	map_width;
	int	map_hight;

	map_win_x = all->mlx_info->win_x / 3;
	map_win_y = all->mlx_info->win_y / 3;
	map_width = map_win_x / all->map->quant_max_col;
	map_hight = map_win_y / (all->map->quant_line - 7);
	return (all->map->all_map[(pixel_y / map_hight) + 8][pixel_x / map_width]);
}
