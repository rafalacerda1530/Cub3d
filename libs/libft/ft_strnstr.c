/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:46:39 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/07 17:39:20 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_inside(const char *principal, const char *inside)
{
	int	i;

	i = 0;
	while (inside[i] != '\0')
	{
		if (principal[i] != inside[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!(*little))
		return ((char *)big);
	i = 0;
	little_len = ft_strlen((char *)little);
	while (*big != '\0' && i + little_len <= len)
	{
		if (*big == little[0])
		{
			if (ft_is_inside(big, little))
				return ((char *)big);
		}
		big++;
		i++;
	}
	return (0);
}
