/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:56:23 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/09 20:40:40 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rush( int x, int y)
{
	int		m;
	int		i;
	int		k;
	char	front;
	char	back;
	char	lain;
	char	midle;

 m = 0 ;
 i = 0 ;
 k = 0 ;

 front = 'A';
 back = 'C';
 lain = 'B'; 
 midle = ' '; 
  if (x > 0 && y > 0){
  	write(1, &front, 1 );
  	while (i < x - 2){
  		write(1, &lain, 1);
  		i++;
  	}
  
	if(x >= 1){
  	write(1, &back, 1);
  	write(1, "\n", 1);
 
	if(y > 1){
  while(k < y - 2)
  { 
  	write(1, &lain, 1);
  	while( x - 2 > m )
  	{
  		write(1, &midle, 1);
  		m++;
  	}
  	m = 0;
  	write(1, &lain, 1);
  	write(1, "\n", 1);
 k++;
  }
  i = 0;
  if (y > 1){
  write(1, &back, 1 );
  while (i < x - 2){
  		write(1, &lain, 1);
  		i++;
  	}
  	write(1, &front, 1 );


}}}}
  else write( 1, "you write no corect x and Y  ", 30);
}

int	main ( void){

	rush(1,5);
	return 0;
}
