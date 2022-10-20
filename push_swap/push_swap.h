/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:05:56 by skeveyan          #+#    #+#             */
/*   Updated: 2022/10/20 15:03:00 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct T_MAIN
{	
	char		*input_ful;
	char		**input_cuts;
	long int	*input_s;
	int			wstrlen;
}				t_main;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*before;
}					t_list;

void		secend_sort(t_list **stec_a, t_list **stec_b, int *grup_qaunt,int caunt );
void		ferst_sorting(t_list **stec_a);
void		speshl_qeys(int count, t_list **stec_a, t_list **stec_b);
void		swap(t_list **swap_argument);
void		push(t_list **take_argument, t_list **put_argument);
void		algoritm(int count, t_list **stec_a, t_list **stec_b );
void		pour(long int	*input, int int_aray_len, t_list **pour_stec);
void		ft_beforeadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content);
void		parsing(long int *exit_int, int otputs_i, char **s);
long int	ft_atoi(const char *str);
char		*ful_join(char **argv);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
size_t		ft_2strlen(char **s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		error_max_min_dupliqet(long int *data, int count);
char		**ft_split( char const *s, char c);
size_t		need_row(const char *s, char c );
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
void		frik(char **s1);
#endif
