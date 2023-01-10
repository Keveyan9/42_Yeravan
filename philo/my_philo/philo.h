/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:16:47 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/11 00:16:52 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct T_INPUT_ARGUMENT
{	
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	int				ok_siqel;
	int				print_lock;
	int				tred_finish;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_print_lock;
}				t_input_argument;

typedef struct PHILO_PARAMETR
{
	t_input_argument	*input;
	pthread_t			thread;
	long long			start;
	long long			tred_finish_id;
	unsigned int		number;
	long long			starteat;
	long long			startsleep;
	long long			startthink;
}						t_philo_parametr;

long int	ft_atoi(const char *str);
int			chek_argument( char **argv, t_input_argument *input);
int			creat_philo(t_philo_parametr *philo_a, t_input_argument *input);
void		ft_usleep(long long tm);
long long	get_time(void);
void		take_forks(t_philo_parametr *philos);
void		put_forks(t_philo_parametr *philos);
void		*logic(void *arg);
void		print_s(char *s, t_philo_parametr *philos);
int			chek_distroy(t_philo_parametr *philo_a, t_input_argument *input);
#endif
