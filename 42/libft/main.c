/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:31 by skeveyan          #+#    #+#             */
/*   Updated: 2022/03/18 14:15:04 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"
 char dest [] = "hello";
int main()
{

	char d = 'w';
	printf("%s",dest);
	ft_memmove(dest,dest+2,2);
	printf("\n");
	printf("%s",dest);
	
}



