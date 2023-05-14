/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:13:04 by akazuki           #+#    #+#             */
/*   Updated: 2023/03/16 15:18:51 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*tmpsave;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (tmp == NULL)
		return (NULL);
	tmpsave = tmp;
	while (*s1 != '\0')
		*tmp++ = *s1++;
	while (*s2 != '\0')
		*tmp++ = *s2++;
	*tmp = '\0';
	return (tmpsave);
}
