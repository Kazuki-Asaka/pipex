/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipexutils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:10:57 by akazuki           #+#    #+#             */
/*   Updated: 2023/04/04 20:57:17 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_dosecondcmd(char *outfile, char *infile, char *argv, int prev_fd)
{
	int	outfd;

	// outfd = open(outfile, O_DIRECTORY);
	// if (outfd != -1)
	// {
	// 	ft_putstr_fd(strerror(EISDIR), 2);
	// 	ft_doclose(outfd);
	// 	exit(1);
	// }
	if (ft_strncmp(infile, "here_doc", 8) == 0)
		outfd = open (outfile, (O_CREAT | O_RDWR | O_APPEND), 0644);
	else
		outfd = open (outfile, (O_CREAT | O_RDWR | O_TRUNC), 0644);
	if (outfd == -1)
	{
		// write(2, "test\n", 5);
		ft_putstr_fd(strerror(errno), 2);
		exit (1);
	}
	ft_dodup2(prev_fd, 0);
	ft_doclose(prev_fd);
	ft_dodup2(outfd, 1);
	ft_doclose(outfd);
	ft_lstcmd(argv);
}

void	ft_middocmd(char	*cmd, int *pipefd, int prev_fd)
{
	char	*path;
	char	**separgv;
	int		check;

	ft_dodup2(prev_fd, 0);
	ft_doclose(prev_fd);
	separgv = ft_dosplit(cmd, ' ');
	if (separgv[0] == NULL)
	{
		perror ("command not found");
		exit (127);
	}
	path = ft_getpath(separgv[0]);
	ft_doclose(pipefd[0]);
	ft_dodup2(pipefd[1], 1);
	ft_doclose (pipefd[1]);
	check = execve(path, separgv, environ);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (127);
	}
}

char	*ft_filecheck(char *file)
{
	if (access(file, X_OK) == 0)
		return (file);
	else
	{
		perror("file");
		exit(127);
	}
}

void	ft_nopipe(char **argv)
{
	pid_t	pid;
	int		check;
	int		infd;

	pid = ft_dofork();
	if (pid == 0)
	{
		infd = open (argv[1], O_RDONLY);
		if (infd == -1)
		{
			// write(2, "test\n", 5);
			ft_putendl_fd(strerror(errno), 2);
			exit (1);
		}
		ft_dodup2(infd, 0);
		ft_doclose(infd);
		ft_nopipefile(argv);
	}
	check = wait (NULL);
	if (check == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit (1);
	}
}

void	ft_nopipefile(char **argv)
{
	int		outfd;
	char	**separgv;
	char	*path;

	separgv = ft_dosplit(argv[2], ' ');
	if (separgv[0] == NULL)
	{
		perror ("command not found");
		exit (127);
	}
	path = ft_getpath(separgv[0]);
	outfd = open (argv[3], (O_CREAT | O_RDWR | O_TRUNC), 0644);
	if (outfd == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit (1);
	}
	ft_dodup2(outfd, 1);
	ft_doclose(outfd);
	ft_nopipecmd(path, separgv);
}
