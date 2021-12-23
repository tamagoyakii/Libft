/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyun <jihyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:44:19 by jihyun            #+#    #+#             */
/*   Updated: 2021/12/16 16:13:37 by jihyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

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
