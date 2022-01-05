/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyun <jihyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:42:24 by jihyukim          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:25 by jihyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		else
		{
			count++;
			while (*(s + i) != c && *(s + i))
				i++;
		}
	}
	return (count);
}

static void	ret_free(char **ret, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(*(ret + i));
		i++;
	}
	free(ret);
	ret = 0;
}

static int	str_copy(char **ret, char const *s, size_t j, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	*(ret + j) = ft_substr(s, 0, len);
	if (!(ret + j))
	{
		ret_free(ret, j);
		return (0);
	}
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t 	i;
	size_t 	j;
	char	**ret;

	if (!s || !c)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (str_count(s, c) + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			i += str_copy(ret, s + i, j, c);
			if (!i)
				return (0);
			j++;
		}
		else
			i++;
	}
	*(ret + j) = 0;
	return (ret);
}
