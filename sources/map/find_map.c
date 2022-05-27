/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:43:14 by rarodrig          #+#    #+#             */
/*   Updated: 2022/05/25 23:04:14 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	i = 0;
	while (len_ext > 0)
	{
		if (extension[--len_ext] == str[--len_str])
			i++;
		else
		{
			printf("Error\nInvalid map extension\n");
			return (0);
		}
	}
	return (1);
}

int	find_map(t_all *all, int argc, char *argv)
{
	int	fd1;

	if (argc == 1)
	{
		printf("Error\nInput need some map .cub\n");
		exiter(all, EXIT_FAILURE);
	}
	if (argc > 2)
		printf("Will be utilized the first file\n");
	if (!check_extension(argv, ".cub"))
		exiter(all, EXIT_FAILURE);
	fd1 = open(argv, O_RDONLY);
	if (fd1 < 0)
	{
		printf("Error\nFile does not exists\n");
		exiter(all, EXIT_FAILURE);
	}
	return (fd1);
}
