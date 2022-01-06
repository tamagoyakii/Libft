/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyun <jihyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:09:41 by jihyukim          #+#    #+#             */
/*   Updated: 2022/01/05 15:33:12 by jihyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			*(unsigned char *)(dst + i - 1)
				= *(const unsigned char *)(src + i - 1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(const unsigned char *)(src + i);
			i++;
		}
	}
	return (dst);
}
