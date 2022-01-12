/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyun <jihyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:44:19 by jihyun            #+#    #+#             */
/*   Updated: 2022/01/12 14:34:23 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (*(s + i))
	{
		*(ret + i) = (*f)(i, *(s + i));
		i++;
	}
	*(ret + i) = 0;
	return (ret);
}
