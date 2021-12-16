/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyun <jihyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:42:24 by jihyukim          #+#    #+#             */
/*   Updated: 2021/12/16 12:37:34 by jihyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		else
		{
			count++;
			while (*(s + i) != c)
				i++;
		}
	}
	return (count);
}

static void	ft_split_free(char **ret)
{
	size_t	i;

	i = 0;
	while (*(ret + i))
	{
		free(*(ret + i));
		i++;
	}
	free(ret);
	ret = 0;
}

static int	ft_split_substr(char **ret, char const *s, int j, char c)
{
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	*(ret + j) = ft_substr(s, 0, len);
	if (!(ret + j))
	{
		ft_split_free(ret);
		return (0);
	}
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**ret;

	if (!s)
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
			i += ft_split_substr(ret, s + i, j, c);
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
