/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:11:39 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/26 15:15:29 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_buffers(t_all *all)
{
	if (all->texture->n_buffer)
		free(all->texture->n_buffer);
	if (all->texture->s_buffer)
		free(all->texture->s_buffer);
	if (all->texture->w_buffer)
		free(all->texture->w_buffer);
	if (all->texture->e_buffer)
		free(all->texture->e_buffer);
}

void	ft_free(t_all *all)
{
	int	i;

	i = -1;
	if (all->map->all_map)
	{
		while (all->map->all_map[++i])
			if (*all->map->all_map[i] || all->map->all_map[i + 1])
				free(all->map->all_map[i]);
		free(all->map->all_map);
	}
	if (all->mlx_info->win_ptr)
		mlx_destroy_window(all->mlx_info->mlx_ptr, all->mlx_info->win_ptr);
	if (all->mlx_info->mlx_ptr)
	{
		mlx_destroy_display(all->mlx_info->mlx_ptr);
		free(all->mlx_info->mlx_ptr);
	}
	free_buffers(all);
}

int	exiter(t_all *all, int exit_number)
{
	ft_free(all);
	exit(exit_number);
	return (0);
}
