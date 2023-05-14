/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazuki <akazuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:21:24 by akazuki           #+#    #+#             */
/*   Updated: 2023/03/26 16:16:00 by akazuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

// int			errno;
extern char	**environ;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
void	ft_pipex(int argc, char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_getpath(char *separgv);
char	**ft_dosplit(char *str, char c);
char	*ft_dostrjoin(char *s1, char *s2);
int		ft_dopipe(int	*pipefd);
pid_t	ft_dofork(void);
int		ft_dodup2(int pipefd, int fd);
int		ft_parents(int *pipefd, size_t i, int argc, int prev_fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_childwait(char **argv, size_t i);
void	ft_doclose(int fd);
void	ft_dofirstcmd(char *infile, char *argv, int *pipefd);
void	ft_docmd(char	*cmd, int *pipefd);
void	ft_dosecondcmd(char *outfile, char *infile, char *argv, int prev_fd);
void	ft_lstcmd(char *cmd);
void	ft_putendl_fd(char *s, int fd);
void	ft_middocmd(char	*cmd, int *pipefd, int prev_fd);
int		ft_heredoc(char *limiter);
char	*ft_filecheck(char *file);
void	ft_nopipefile(char **argv);
void	ft_nopipe(char **argv);
void	ft_nopipecmd(char *path, char **separgv);
void	ft_onlyheredoc(char **argv);

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(const char *s, int c);
void	ft_bzero(void	*s, size_t	n);
size_t	ft_strlen_add(const char *str, char c);
void	ft_argccheck(int argc);

#endif