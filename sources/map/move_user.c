/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:51:30 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/23 19:00:01 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_up(t_all *all)
{
	int	y;
	int	x;

	y = all->map->user_y + 0.2 * cos((all->map->user_view) * PI / 180);
	x = all->map->user_x + 0.2 * sin((all->map->user_view) * PI / 180);
	if (all->map->all_map[y][x] == '1')
		return ;
	all->map->user_y += 0.2 * cos((all->map->user_view) * PI / 180);
	all->map->user_x += 0.2 * sin((all->map->user_view) * PI / 180);
}

void	move_down(t_all *all)
{
	int	y;
	int	x;

	y = all->map->user_y - 0.3 * cos((all->map->user_view) * PI / 180);
	x = all->map->user_x - 0.3 * sin((all->map->user_view) * PI / 180);
	if (all->map->all_map[y][x] == '1')
		return ;
	all->map->user_y -= 0.2 * cos((all->map->user_view) * PI / 180);
	all->map->user_x -= 0.2 * sin((all->map->user_view) * PI / 180);
}

void	move_left(t_all *all)
{
	int	y;
	int	x;

	y = all->map->user_y - 0.3 * sin((all->map->user_view) * PI / 180);
	x = all->map->user_x + 0.3 * cos((all->map->user_view) * PI / 180);
	if (all->map->all_map[y][x] == '1')
		return ;
	all->map->user_x += 0.2 * cos((all->map->user_view) * PI / 180);
	all->map->user_y -= 0.2 * sin((all->map->user_view) * PI / 180);
}

void	move_right(t_all *all)
{
	int	y;
	int	x;

	y = all->map->user_y + 0.3 * sin((all->map->user_view) * PI / 180);
	x = all->map->user_x - 0.3 * cos((all->map->user_view) * PI / 180);
	if (all->map->all_map[y][x] == '1')
		return ;
	all->map->user_x -= 0.2 * cos((all->map->user_view) * PI / 180);
	all->map->user_y += 0.2 * sin((all->map->user_view) * PI / 180);
}

void	rotate(t_all *all, int signal)
{
	if (all->map->user_view <= 0 && signal < 0)
		all->map->user_view = 360;
	else if (all->map->user_view >= 360 && signal > 0)
		all->map->user_view = 0;
	all->map->user_view += 10 * signal;
	init_map(all->mlx_info, &all->mlx_info->map, all);
	init_map(all->mlx_info, &all->mlx_info->map, all);
	init_view(all->mlx_info, &all->mlx_info->view, all);
}
