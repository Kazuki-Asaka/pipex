/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipexbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:15:08 by akazuki           #+#    #+#             */
/*   Updated: 2023/04/04 20:25:08 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_lstcmd(char *cmd)
{
	char	*path;
	char	**separgv;
	int		check;

	separgv = ft_dosplit(cmd, ' ');
	if (separgv[0] == NULL)
	{
		perror ("command not found");
		exit (127);
	}
	path = ft_getpath(separgv[0]);
	check = execve(path, separgv, environ);
	if (check == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (127);
	}
}

void	ft_docmd(char	*cmd, int *pipefd)
{
	char	*path;
	char	**separgv;
	int		check;

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
	// write(2, "test\n", 5);
	check = execve(path, separgv, environ);
	// write(0, "test\n", 5);
	if (check == -1)
	{
		// write(2, "test\n", 5);
		ft_putstr_fd(strerror(errno), 2);
		exit (127);
	}
}

void	ft_pipex(int argc, char **argv)
{
	size_t	i;
	pid_t	pid;
	int		pipefd[2];
	int		prev_fd;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		prev_fd = ft_heredoc(argv[2]);
		i = i + 1;
	}
	while (i <= (size_t)argc - 2)
	{
		if (i != (size_t)argc -2 && argc != 4)
			ft_dopipe(pipefd);
		pid = ft_dofork();
		if (pid == 0 && i == 2 && argc != 4)
			ft_dofirstcmd(argv[1], argv[i], pipefd);
		else if (pid == 0 && i == (size_t)argc -2)
			ft_dosecondcmd(argv[argc - 1], argv[1], argv[i], prev_fd);
		else if (pid == 0)
			ft_middocmd(argv[i], pipefd, prev_fd);
		prev_fd = ft_parents(pipefd, ++i, argc, prev_fd);
	}
	ft_childwait(argv, i);
}

int	ft_heredoc(char *limiter)
{
	int		pipefd[2];
	char	*str;
	int		prev_fd;

	ft_dopipe(pipefd);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		else if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, pipefd[1]);
		free(str);
	}
	prev_fd = pipefd[0];
	ft_doclose(pipefd[1]);
	return (prev_fd);
}

// __attribute__((destructor))
// static void destructor(void){
//     system("leaks -q pipex");
// }

int	main(int argc, char **argv)
{
	ft_argccheck(argc);
	if (argc == 4)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
			ft_onlyheredoc(argv);
		else
			ft_nopipe(argv);
	}
	else
		ft_pipex(argc, argv);
}
