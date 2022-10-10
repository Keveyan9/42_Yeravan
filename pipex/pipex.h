/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:11:42 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/09 22:31:11 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct T_CHILD{
	int		i_fd;
	int		o_fd;
	char	**path;
	int		pid1;
	int		pid2;
	int		pip[2];
	int		argv_i;
}			t_child;

void	chekin_file(char **fd, int argc, t_child *var);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	**faund_path(char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split( char const *s, char c);
size_t	need_row(const char *s, char c );
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	frik(char **s1);
char	*chekin_comands_path( char **path, char *comands);
void	ferst_child(char *argv, char **env, t_child *var );
void	last_child(char *argv, char **env, t_child *var);
void	close_pip(t_child *var);
#endif
