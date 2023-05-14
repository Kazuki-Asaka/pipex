/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:26:05 by akazuki           #+#    #+#             */
/*   Updated: 2023/03/26 14:03:34 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_accesscheck(char *flag, char *separgv)
{
	char	**sepflag;
	size_t	i;
	char	*path;
	int		check;
	char	*tmp;

	i = 0;
	sepflag = ft_dosplit(flag, ':');
	while (sepflag[i] != NULL)
	{
		tmp = ft_dostrjoin(sepflag[i], "/");
		path = ft_dostrjoin(tmp, separgv);
		free(tmp);
		check = access(path, X_OK);
		if (check == 0)
		{
			return (path);
			break ;
		}
		free (path);
		i++;
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(separgv, 2);
	exit (127);
}

char	*ft_getpath(char *separgv)
{
	size_t	i;
	char	*flag;

	i = 0;
	flag = NULL;
	if (ft_strchr(separgv, '/') == 1)
		return (ft_filecheck(separgv));
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
		{
			flag = environ[i];
			break ;
		}
		i++;
	}
	if (flag == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(separgv, 2);
		exit (127);
	}
	flag = flag + ft_strlen("PATH=");
	return (ft_accesscheck(flag, separgv));
}
