/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:34:48 by jihyukim          #+#    #+#             */
/*   Updated: 2021/12/09 18:41:54 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (len <= 0 || !s || start >= ft_strlen(s))
		return (0);
	ret = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(ret + i) = *(s + start * i);
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
