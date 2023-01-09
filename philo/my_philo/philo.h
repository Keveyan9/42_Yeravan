#ifndef PHILO_H
#define PHILO_H
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "stdlib.h"
#include <sys/time.h>

typedef struct T_INPUT_ARGUMENT
{	
	 int				philo;
	 int				die;
	 int				eat;
	 int				sleep;
	 int				ok_siqel;
	 int			print_lock;
	 int				tred_finish;
	 pthread_mutex_t	*fork;
	 pthread_mutex_t	m_print_lock;
}				t_input_argument;

typedef struct	PHILO_PARAMETR
{
	t_input_argument	*input;
	pthread_t			thread;
	unsigned	int		tred_finish_id;
	unsigned	int		number;
	unsigned	int		starteat;
	unsigned	int		startsleep;
	unsigned	int		startthink;
}					philo_parametr;


long int	ft_atoi(const char *str);
int	chek_argument( char **argv, t_input_argument *input);
int creat_philo(philo_parametr *philo_a,t_input_argument *input);
void take_forks(philo_parametr *philos);
void put_forks(philo_parametr *philos);
int chek_distroy_eats_moment(philo_parametr *philos);
int chek_distroy_sleep_moment(philo_parametr *philos);
unsigned int  timer();
void *chek(void *arg);

void print_s(char *s, philo_parametr *philos);
#endif

