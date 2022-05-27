/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:09:46 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/26 19:10:14 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*get_arg_init(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (&line[i]);
}

void	get_textures(t_all *all, char *line)
{
	if (!ft_strncmp("NO", line, 2)
		&& open(get_arg_init(&line[3]), O_RDONLY) >= 0)
		all->texture->n = get_arg_init(&line[3]);
	if (!ft_strncmp("WE", line, 2)
		&& open(get_arg_init(&line[3]), O_RDONLY) >= 0)
		all->texture->w = get_arg_init(&line[3]);
	if (!ft_strncmp("SO", line, 2)
		&& open(get_arg_init(&line[3]), O_RDONLY) >= 0)
		all->texture->s = get_arg_init(&line[3]);
	if (!ft_strncmp("EA", line, 2)
		&& open(get_arg_init(&line[3]), O_RDONLY) >= 0)
		all->texture->e = get_arg_init(&line[3]);
	if (!ft_strncmp("F", line, 1))
		all->texture->f = get_arg_init(&line[1]);
	if (!ft_strncmp("C", line, 1))
		all->texture->c = get_arg_init(&line[1]);
}
