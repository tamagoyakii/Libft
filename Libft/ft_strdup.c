/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:46:44 by jihyukim          #+#    #+#             */
/*   Updated: 2021/12/08 14:29:27 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
