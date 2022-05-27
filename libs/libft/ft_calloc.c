/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:49:48 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 18:19:22 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*pointer;
	size_t	total_size;

	total_size = nmemb * size;
	pointer = (void *)malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, total_size);
	return (pointer);
}
