/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:55:53 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 16:48:12 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	char	*str_join_init;

	str_join = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!str_join || (s1 == NULL && s2 == NULL))
		return (NULL);
	str_join_init = str_join;
	while (*s1)
	{
		*str_join = *s1;
		str_join++;
		s1++;
	}
	while (*s2)
	{
		*str_join = *s2;
		str_join++;
		s2++;
	}
	*str_join = '\0';
	return (str_join_init);
}
