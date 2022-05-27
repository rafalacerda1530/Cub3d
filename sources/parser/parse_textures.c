/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:55:57 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/25 23:03:14 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	load_imgs(t_all *all)
{
	all->texture->n_img.img = mlx_xpm_file_to_image(all->mlx_info->mlx_ptr,
			(*all->texture).n, &all->texture->n_img.x, &all->texture->n_img.y);
	all->texture->s_img.img = mlx_xpm_file_to_image(all->mlx_info->mlx_ptr,
			(*all->texture).s, &all->texture->s_img.x, &all->texture->s_img.y);
	all->texture->w_img.img = mlx_xpm_file_to_image(all->mlx_info->mlx_ptr,
			(*all->texture).w, &all->texture->w_img.x, &all->texture->w_img.y);
	all->texture->e_img.img = mlx_xpm_file_to_image(all->mlx_info->mlx_ptr,
			(*all->texture).e, &all->texture->e_img.x, &all->texture->e_img.y);
	if (!all->texture->n_img.img || !all->texture->s_img.img
		|| !all->texture->w_img.img || !all->texture->e_img.img)
		return (1);
	return (0);
}

static void	load_img_add(t_texture *texture)
{
	texture->n_img.addr = mlx_get_data_addr(texture->n_img.img,
			&texture->n_img.bits_per_pixel, &texture->n_img.line_length,
			&texture->n_img.endian);
	texture->s_img.addr = mlx_get_data_addr(texture->s_img.img,
			&texture->s_img.bits_per_pixel, &texture->s_img.line_length,
			&texture->s_img.endian);
	texture->w_img.addr = mlx_get_data_addr(texture->w_img.img,
			&texture->w_img.bits_per_pixel, &texture->w_img.line_length,
			&texture->w_img.endian);
	texture->e_img.addr = mlx_get_data_addr(texture->e_img.img,
			&texture->e_img.bits_per_pixel, &texture->e_img.line_length,
			&texture->e_img.endian);
}

static void	load_buffer(t_texture *text)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	text->n_buffer = ft_calloc((64 * 64), sizeof(__uint32_t *));
	text->s_buffer = ft_calloc((64 * 64), sizeof(__uint32_t *));
	text->w_buffer = ft_calloc((64 * 64), sizeof(__uint32_t *));
	text->e_buffer = ft_calloc((64 * 64), sizeof(__uint32_t *));
	while (x < 64)
	{
		while (y < 64)
		{
			text->n_buffer[(64 * y) + x] = get_color_pxl(&text->n_img, x, y);
			text->s_buffer[(64 * y) + x] = get_color_pxl(&text->s_img, x, y);
			text->w_buffer[(64 * y) + x] = get_color_pxl(&text->w_img, x, y);
			text->e_buffer[(64 * y) + x] = get_color_pxl(&text->e_img, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

static void	destroy_imgs(t_all *all)
{
	if (all->texture->n_img.img)
		mlx_destroy_image(all->mlx_info->mlx_ptr, all->texture->n_img.img);
	if (all->texture->s_img.img)
		mlx_destroy_image(all->mlx_info->mlx_ptr, all->texture->s_img.img);
	if (all->texture->e_img.img)
		mlx_destroy_image(all->mlx_info->mlx_ptr, all->texture->e_img.img);
	if (all->texture->w_img.img)
		mlx_destroy_image(all->mlx_info->mlx_ptr, all->texture->w_img.img);
}

int	create_textures_img(t_all *all)
{
	if (load_imgs(all))
	{
		destroy_imgs(all);
		printf("Error\n Textures Parse\n");
		return (1);
	}
	load_img_add(all->texture);
	load_buffer(all->texture);
	destroy_imgs(all);
	return (0);
}
