/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:45:14 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/10 07:55:06 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_tlist;

	new_tlist = (t_list *)malloc(sizeof(t_list));
	if (new_tlist)
	{
		new_tlist->next = NULL;
		new_tlist->content = content;
	}
	return (new_tlist);
}
