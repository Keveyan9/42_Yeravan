/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:04 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/02 22:38:15 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*returnline;
	static char	*temporary;
	char readback[BUFFER_SIZE + 1];
	size_t	i_read;
	size_t	i_temporary;
	ssize_t read_back_size;
	int n ;


	//if(temporary)
		temporary = (char * ) malloc(5);
		temporary[0]='1';
		temporary[1]='2';
		temporary[2]='\n';
		temporary[3]='1';
		temporary[4]='\0';

		printf("==%s==\n",return_chekin(temporary));
		//printf("+++%s++",temporary);


// 	n = 1;
// 	while (1)
// 	{
// 		i_read = 0;
// 		i_temporary = 0; 
// 		read_back_size = 0;
// 		read_back_size = read(fd, readback, BUFFER_SIZE);
// 		readback[read_back_size] ='\0';
// 		if(read_back_size == 0 )
// 			return(NULL);
// 		while (temporary && temporary[i_temporary]!='\n' && temporary[i_temporary])
// 			i_temporary++;
// 		while (readback[i_read] && readback[i_read]!= '\n'&& readback[i_read] && temporary[i_temporary]!='\n')
// 			i_read++;
// 		if(readback[i_read] =='\n' ||temporary[i_temporary]=='\n' )
// 			n = 2 ;
// 		returnline = (char *) malloc (i_read + i_temporary + n);
// 		if(!returnline)
// 			return(NULL);
// 		i_temporary = 0;
// 		i_read = 0; 
// 		while (temporary && temporary[i_temporary]!='\n'&& temporary[i_temporary])
// 			{
// 				returnline[i_temporary] = temporary[i_temporary];
// 				i_temporary++;
// 			}
// 		if(temporary[i_temporary]=='\n')
// 		{
// 			returnline[i_temporary] = '\n';
// 			returnline[i_temporary + 1] = '\0';
// 			return(returnline);
// 		}
// 		while (readback[i_read] && readback[i_read] !='\n' && readback[i_read] !='\0' )
// 		{
// 			returnline[i_temporary+i_read] = readback[i_read];
// 			i_read++;
// 		}
// 		returnline[i_temporary + i_read] = '\0';
// 		if(readback[i_read] =='\0'|| temporary[i_temporary]== '\0')
// 			return (returnline);

// 		if (readback[i_read ] =='\n')
// 		{
// 			returnline[i_temporary + i_read] = '\n';
// 			returnline[i_temporary + (++i_read)] = '\0';

// 			if(temporary[i_temporary]!='\n' && temporary[i_temporary + 1 ])
// 				{
// 					free(temporary);
// 					temporary = (char *) malloc( read_back_size - i_read);
// 					 if(!temporary)
// 					return(NULL);
// 					i_temporary = 0;
// 					while (readback[i_read])
// 					temporary[i_temporary++] = readback[++i_read];
// 					temporary[i_temporary++] = '\0';
// 				}
// 			return (returnline);
// 		}
// 		free(temporary);
// 		temporary = (char *) malloc(i_temporary+i_read + 1);
// 			if(!temporary)
// 				return(NULL);
// 		i_read = 0;
// 	while(returnline[i_read])
// 	{
// 		temporary[i_read] = returnline[i_read];
// 		i_read++;
// 	}
// 	temporary[i_read++] = '\0';
// 	free(returnline);
// }
return(NULL);
}


int main()
{
	int fd1;
	// int fd2;
	// char readback[BUFFER_SIZE + 1];
	//  fd1 = open("text.txt", O_RDONLY);
	// printf("--%zu--\n", read(fd1, readback, BUFFER_SIZE));
	//  readback[BUFFER_SIZE ]='\0';
	// printf("---%s---\n",readback);
	//write(1,&readback[0],1);

	// printf("%d", fd1);
	fd1 = open("text.txt", O_RDONLY);
	get_next_line(fd1);
	//printf("-1--%s---\n", get_next_line(fd1));
		//  printf("--2-%s---\n", get_next_line(fd1));
		// printf("--3-%s---\n", get_next_line(fd1));
		// 	printf("--4-%s---\n", get_next_line(fd1));
	//get_next_line(fd1);
	// fd2 = open("test2.txt", O_RDONLY);
	//	printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd2));
}

//1 stugel static char * - mej ka ? - \n
	//2 ete ka veradarcnel asdad\n jnnjel ayd masy static char * -ic asdad\n
	//3 ete chka \n -> kardal -> join anel hin static char*-in -> stugel ka? \n ancum qayl 2
