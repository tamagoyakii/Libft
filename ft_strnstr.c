/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:29:24 by jihyukim          #+#    #+#             */
/*   Updated: 2021/12/08 17:11:36 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i) && i + ft_strlen(needle) - 1 < len)
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			while (*(needle + j) && *(needle + j) == *(haystack + i + j))
			{
				j++;
			}
			if (!*(needle + j))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
