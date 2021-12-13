/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:42:24 by jihyukim          #+#    #+#             */
/*   Updated: 2021/12/13 20:07:34 by jihyukim         ###   ########.fr       */
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

static char	*ft_split_substr(char **ret, char const *s, size_t start, char c)
{
	size_t	len;
	char	*arr;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	arr = ft_substr(s, start, len);
	if (!arr)
		ft_split_free(ret);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
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
			*(ret + j) = ft_split_substr(ret, s + i, i, c);
			if (!(*(ret + j++)))
				return (0);
		}
		else
			i++;
	}
	*(ret + j) = 0;
	return (ret);
}

#include <stdio.h>

int main(void)
{
	char *a = "hello world! my name is jihyukim ahha ";
	char b = ' ';
	char **c = ft_split(a, b);
	while (*c)
	{
		printf("%s\n", *c);
		c++;
	}
	return (0);
}
