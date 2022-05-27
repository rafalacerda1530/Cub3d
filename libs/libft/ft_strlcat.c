/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:02:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 16:48:20 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	loop;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen((char *)src);
	loop = 0;
	if (size <= dst_length)
		return (size + src_length);
	while (loop < (size - dst_length - 1) && src[loop])
	{
		dst[dst_length + loop] = src[loop];
		loop++;
	}
	dst[dst_length + loop] = '\0';
	return (dst_length + src_length);
}
