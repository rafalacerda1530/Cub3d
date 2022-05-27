/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:29:56 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 16:48:41 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (r != 0)
			return (r);
		i++;
	}
	return (r);
}
