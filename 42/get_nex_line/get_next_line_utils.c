/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:53 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/02 22:38:56 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char *return_chekin(char *s1)
{
	size_t	i_temporary;
	char	*returnts1;

	i_temporary = 0;
	while ( s1[i_temporary]!='\n' && s1[i_temporary])
			i_temporary++;
	if(s1[i_temporary]=='\n')
		i_temporary++;
	returnts1 =(char *)malloc(i_temporary+1);
	if(!returnts1)
		return(NULL);
	i_temporary = 0;
	while (s1[i_temporary]!='\n'&& s1[i_temporary])
	{
		returnts1[i_temporary] = s1[i_temporary];
		i_temporary++;
	}
	if(s1[i_temporary] =='\n')
		returnts1[i_temporary++]='\n';
	returnts1[i_temporary]='\0';
	//if(s1[i_temporary])
		//cat(temporary,i_temporary);
	return(returnts1);
}

// void cat (char *cattemporary,int i_temporary)
// {
// 	size_t	i_cattemp;
// 	char *returuncat;
	
// 	returuncat = (*char) malloc(ft_strlen(cattemporary[i_temporary]));
// 	if(!returuncat)
// 		return(NULL);
// 	while (cattemporary[i_cattemp])
// 	{
// 		returuncat[i_cattemp] = cattemporary[i_cattemp]
// 		i_cattemp++;
// 	}
// 	free(cattemporary)
// 	cattemporary = (char*) malloc(i_cattemp+1);
// 	i_cattemp=0;
// 	while (returuncat[i_cattemp])
// 	{
// 		cattemporary[i_cattemp] == returuncat[i_cattemp];
// 		i_cattemp++;
// 	}
// 	cattemporary[i_cattemp] = '\0';

// }



// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*nowstring;
// 	size_t	n;
// 	size_t	t;

// 	n = 0;
// 	t = 0;
// 	nowstring = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!nowstring)
// 		return (0);
// 	while (s1[n])
// 	{	
// 		nowstring[n] = s1[n];
// 		n++;
// 	}
// 	while (s2[t])
// 		nowstring[n++] = s2[t++];
// 	nowstring[n++] = '\0';
// 	return (nowstring);
// }
