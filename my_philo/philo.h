#ifndef PHILO_H
#define PHILO_H
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "stdlib.h"
#include <sys/time.h>

typedef struct T_INPUT_ARGUMENT
{	
	 int	philo;
	 int	die;
	 int	eat;
	 int	sleep;
	 int	ok_time;
}				t_input_argument;

typedef struct T_PTHREAD_ARGUMENT
{
	pthread_mutex_t *fork;
	pthread_t 		*thread;
	unsigned	int	number;
	unsigned	int	ms;
	unsigned	int *starteat;
	unsigned	int *startsleep;
	unsigned	int *startthink;
	t_input_argument *input;
}	t_pthread_argument;

unsigned int  timer();
void put_forks(t_pthread_argument *pthread, int n);
void take_forks(t_pthread_argument *pthread,int n);
long int	ft_atoi(const char *str);
int	chek_argument( char **argv, t_input_argument *input);
int creat_philo(t_input_argument *input,t_pthread_argument *pthread);
int chek_distroy(t_pthread_argument *pthread);
#endif

