/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:26:17 by akazuki           #+#    #+#             */
/*   Updated: 2023/04/04 19:47:02 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_malloc_check(char **tmp, int count)
{
	while (count >= 0)
	{
		free (*tmp);
		(*tmp)--;
		count--;
	}
	free (tmp);
	return (NULL);
}

static int	ft_strlen_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static char	*ft_set(char **tmp, char const *s, char c)
{
	int		i;
	char	**tmp1;
	int		count;

	tmp1 = tmp;
	count = 0;
	while (*s != '\0')
	{
		i = ft_strlen_c(s, c);
		if (*s == '\0' || i > 0)
		{
			*tmp = malloc (sizeof(char) * i + 1);
			if (*tmp == NULL)
				return (ft_malloc_check(tmp, count));
			ft_strlcpy (*tmp, (const char *)s, i + 1);
			tmp++;
			count++;
			s = s + i;
		}
		else
			s++;
	}
	*tmp = NULL;
	return (*tmp1);
}

static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (*(s + 1) == c || *(s + 1) == '\0')
				count++;
		}
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	char	**tmp1;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_count(s, c);
	tmp = malloc (sizeof(char *) * (count + 1));
	if (tmp == NULL)
		return (NULL);
	tmp1 = tmp;
	ft_set (tmp, s, c);
	return (tmp1);
}
