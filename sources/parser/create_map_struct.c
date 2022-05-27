/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:14:03 by rarodrig          #+#    #+#             */
/*   Updated: 2022/05/26 19:09:29 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	valid_textures(t_all *all)
{
	int	i;

	i = -1;
	while (all->map->all_map[++i])
	{
		get_textures(all, all->map->all_map[i]);
	}
}

static int	valid_user_position(t_map *map, int counter_line, int counter_col)
{
	if (map->user_x != -1)
	{
		printf("Error\nMap must have only one user");
		return (1);
	}
	if (map->all_map[counter_line][counter_col] == 'N')
		map->user_view = N;
	if (map->all_map[counter_line][counter_col] == 'W')
		map->user_view = W;
	if (map->all_map[counter_line][counter_col] == 'E')
		map->user_view = E;
	if (map->all_map[counter_line][counter_col] == 'S')
		map->user_view = S;
	map->user_x = counter_col + 0.5;
	map->user_y = counter_line + 0.5;
	return (0);
}

int	is_valid_char(char character, t_map *map, int counter_line, int counter_col)
{
	if (character != '1' && character != '0'
		&& character != 'N' && character != 'S'
		&& character != 'E' && character != ' '
		&& character != 'W')
		return (0);
	if (character != '1' && character != '0' && character != ' ')
		if (valid_user_position(map, counter_line, counter_col))
			return (0);
	return (1);
}

static int	validate_map_char(t_map *map)
{
	int	counter_line;
	int	counter_col;

	counter_line = 8;
	counter_col = 0;
	while (map->all_map[counter_line] && map->all_map[counter_line][0] != '\0')
	{
		while (map->all_map[counter_line][counter_col] != '\0')
		{
			if (!is_valid_char(map->all_map[counter_line][counter_col], map,
				counter_line, counter_col))
			{
				printf("Error\nInvalid map char\n");
				return (1);
			}
			counter_col++;
		}
		counter_col = 0;
		counter_line++;
	}
	map->quant_line = counter_line - 1;
	return (0);
}

void	parse_map(t_all *all, int fd1)
{
	int	i;

	i = 0;
	while (get_next_line(fd1, &all->map->all_map[i]))
		i++;
	if (validate_map_char(all->map))
		exiter(all, EXIT_FAILURE);
	valid_textures(all);
	if (!all->texture->n || !all->texture->e || !all->texture->w
		|| !all->texture->s || !all->texture->f || !all->texture->c)
	{
		printf("Error\nTexture error\n");
		exiter(all, EXIT_FAILURE);
	}
	if (validate_map_struct(all->map))
		exiter(all, EXIT_FAILURE);
	rgb_to_decimal(all);
	if (all->map->user_x == -1)
	{
		printf("Error\nMap must have a user\n");
		exiter(all, EXIT_FAILURE);
	}
}
