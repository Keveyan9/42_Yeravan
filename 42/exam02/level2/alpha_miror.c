/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_miror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:03:23 by skeveyan          #+#    #+#             */
/*   Updated: 2022/09/01 14:49:03 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int main(int argv, char **argc )
{
	int n ;
	
	n = 0;
	char nb;
	if(argv == 2)
	{
		while(argc[1][n])
		{
			if(argc[1][n] > 64 && argc[1][n] < 91)
				nb = 'Z'-argc[1][n] + 'A';
			else if(argc[1][n] > 96 && argc[1][n] < 123)
				nb = 'z' - argc[1][n]+ 'a';
			write(1,&nb,1);
			n++;
		}
		write(1,"\n",1);
		return(0);
	}
}
