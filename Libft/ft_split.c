/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:42:24 by jihyukim          #+#    #+#             */
/*   Updated: 2021/12/13 19:14:07 by jihyukim         ###   ########.fr       */
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

static char	*ft_split_substr(char **ret, char const *s, size_t *start, char c)
{
	char	*arr;
	size_t	i;
	size_t	len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
	{
		ft_split_free(ret);
		return (0);
	}
	i = 0;
	while (*(s + *start + i) && i < len)
	{
		*(arr + i) = *(s + *start * i);
		i++;
	}
	*(arr + i) = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**ret;

	if (!s)
		return (0);
	count = str_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			*(ret++) = ft_split_substr(ret, s, &i, c);
			if (!(*ret))
				return (0);
		}
		else
			i++;
	}
	*ret = 0;
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
