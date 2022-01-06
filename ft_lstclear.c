/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyun <jihyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:13:57 by jihyun            #+#    #+#             */
/*   Updated: 2022/01/06 16:39:51 by jihyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_free;
    t_list  *seek;

	if (!del)
		return ;
    seek = *lst;
	while (seek)
	{
		to_free = seek;
        seek = seek->next;
		ft_lstdelone(to_free, del);
	}
    *lst = 0;
}
