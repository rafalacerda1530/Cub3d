/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_hits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:50:19 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/23 18:52:43 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_horizontal_hit(t_all *all, int j, t_dot *dot)
{
	if ((int)(all->map->user_view - j) % 360 >= 180)
		dot->wall_hit = W;
	else
		dot->wall_hit = E;
}

void	set_vertical_hit(t_all *all, int j, t_dot *dot)
{
	if ((int)(all->map->user_view - j) % 360 >= 270
		|| (int)(all->map->user_view - j) % 360 <= 90)
		dot->wall_hit = S;
	else
		dot->wall_hit = N;
}
