/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:26:26 by akazuki           #+#    #+#             */
/*   Updated: 2023/03/16 15:18:44 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	n;

	n = 1;
	srcsize = ft_strlen(src);
	if (dstsize == 0 && *src && dest == NULL)
		return (srcsize + dstsize);
	if (dstsize != 0)
	{
		if (srcsize >= dstsize)
		{
			while (n++ <= dstsize - 1)
				*dest++ = *src++;
			*dest = '\0';
		}
		else
		{
			while (*src != '\0')
			{
				*dest++ = *src++;
			}
			*dest = '\0';
		}
	}
	return (srcsize);
}
