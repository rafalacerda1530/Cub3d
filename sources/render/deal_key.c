/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:08:26 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/11 21:34:04 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	deal_key(int key, t_all *all)
{
	if (key == KESC)
		exiter(all, 0);
	else if (key == KUP)
		move_up(all);
	else if (key == KDOWN)
		move_down(all);
	else if (key == KLEFT)
		move_left(all);
	else if (key == KRIGHT)
		move_right(all);
	else if (key == KARROWLEFT)
		rotate(all, 1);
	else if (key == KARROWRIGHT)
		rotate(all, -1);
	init_map(all->mlx_info, &all->mlx_info->map, all);
	init_view(all->mlx_info, &all->mlx_info->view, all);
	return (0);
}
