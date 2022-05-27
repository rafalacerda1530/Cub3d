/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:44:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/07 18:00:54 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_times(char const *s, char c)
{
	int	i;
	int	is_sequence;
	int	c_times;

	i = -1;
	c_times = 0;
	is_sequence = 1;
	while (s[++i])
	{
		if (s[i] != c && is_sequence)
		{
			c_times++;
			is_sequence = 0;
		}
		else if (s[i] == c)
			is_sequence = 1;
	}
	return (c_times);
}

static size_t	size_words(const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	**fill_array(char const *s, char c, char **split)
{
	int		i;
	char	**return_split;

	i = 0;
	return_split = split;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		else
		{
			*split = ft_substr(&s[i], 0, size_words(&s[i], c));
			if (!split)
				return (NULL);
			i = i + size_words(&s[i], c);
			split++;
		}
	}
	*split = NULL;
	return (return_split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		c_times;

	if (!s)
		return (NULL);
	c_times = ft_count_times(s, c);
	split = (char **)ft_calloc(sizeof(char *), (c_times + 1));
	if (!split)
		return (NULL);
	split = fill_array(s, c, split);
	if (split == NULL)
		return (NULL);
	return (split);
}
