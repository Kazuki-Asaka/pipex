/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipexutils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:24:34 by akazuki           #+#    #+#             */
/*   Updated: 2023/04/04 20:55:24 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_parents(int *pipefd, size_t i, int argc, int prev_fd)
{
	if (i == 3)
	{
		prev_fd = pipefd[0];
		ft_doclose(pipefd[1]);
		return (prev_fd);
	}
	else if (i == (size_t)argc - 1)
	{
		ft_doclose(prev_fd);
		return (0);
	}
	else
	{
		ft_doclose(prev_fd);
		prev_fd = pipefd[0];
		ft_doclose(pipefd[1]);
		return (prev_fd);
	}
}

void	ft_childwait(char **argv, size_t i)
{
	int	check;

	check = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = i - 1;
	while (i > 2)
	{
		check = wait (NULL);
		if (check == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit (1);
		}
		i--;
	}
}

void	ft_doclose(int fd)
{
	int	check;

	check = 0;
	check = close(fd);
	if (check == -1)
	{
		perror("close");
		exit (1);
	}
}

void	ft_argccheck(int argc)
{
	if (argc <= 3)
	{
		perror("./pipex file1 cmd1 cmd2 file2");
		exit (1);
	}
}

void	ft_dofirstcmd(char *infile, char *argv, int *pipefd)
{
	int	infd;

	// infd = open(infile, O_DIRECTORY);
	// if (infd != -1)
	// {
	// 	ft_putstr_fd(argv, 2);
	// 	ft_putstr_fd(" stdin", 2);
	// 	ft_putstr_fd(strerror(EISDIR), 2);
	// 	ft_doclose(infd);
	// 	exit(1);
	// }
	infd = open(infile, O_RDONLY);
	if (infd == -1)
	{
		// write(2, "test\n", 5);
		ft_putstr_fd(strerror(errno), 2);
		ft_doclose(pipefd[0]);
		ft_doclose(pipefd[1]);
		exit (1);
	}
	ft_dodup2(infd, 0);
	ft_doclose(infd);
	ft_docmd(argv, pipefd);
}
