/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipexutils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:02:49 by akazuki           #+#    #+#             */
/*   Updated: 2023/03/26 16:43:47 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_nopipecmd(char *path, char **separgv)
{
	int	check;

	check = execve(path, separgv, environ);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (127);
	}
}

void	ft_onlyheredoc(char **argv)
{
	char	*str;
	int		outfd;

	outfd = open (argv[3], (O_CREAT | O_RDWR | O_APPEND), 0644);
	if (outfd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit (1);
	}
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		else if (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
		{
			free (str);
			break ;
		}
		ft_putstr_fd(str, outfd);
		free(str);
	}
}
