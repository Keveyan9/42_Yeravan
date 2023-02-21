#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#endif
void  chekin_file(char **fd,int argc,int *i_fd, int *o_fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char **faund_path(char **env);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split( char const *s, char c);
size_t	need_row(const char *s, char c );
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void frik(char **s1);
char ** chekin_comands( int argc,char **argv, char **env,int *path_chek_i);

typedef struct T_CHEK_COMANDS{
	
	char **comands_path;
	char **path;
	char *path_chek;
	char *comand_slesh;
	char **comands;
	int comands_n ;
	int path_i;	
}t_chek_comands;

