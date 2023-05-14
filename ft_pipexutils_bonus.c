/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipexutils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:31:39 by akazuki           #+#    #+#             */
/*   Updated: 2023/03/21 16:24:48 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_dosplit(char *str, char c)
{
	char	**tmp;

	tmp = ft_split(str, c);
	if (tmp == NULL)
	{
		perror("spliterror");
		exit(1);
	}
	return (tmp);
}

char	*ft_dostrjoin(char *s1, char *s2)
{
	char	*path;

	path = ft_strjoin(s1, s2);
	if (path == NULL)
	{
		perror("strjoinerror");
		exit(1);
	}
	return (path);
}

int	ft_dopipe(int	*pipefd)
{
	int	check;

	check = pipe(pipefd);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (check);
}

pid_t	ft_dofork(void)
{
	pid_t	check;

	check = fork();
	if (check < 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (check);
}

int	ft_dodup2(int pipefd, int fd)
{
	int	check;

	check = dup2(pipefd, fd);
	if (check == -1)
	{
		perror("dup2");
		exit (1);
	}
	else
		return (check);
}
