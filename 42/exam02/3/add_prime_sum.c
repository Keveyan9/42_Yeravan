#include<unistd.h>
#include<stdio.h>
void ft_atoi(int *num, char *input)
{
 	while ( *input != '\0')
	{
		if (*input < '0' || *input >'9')
		{ 
			*num = -1;
		   break;
		}	   
		*num = *num * 10 + ( *input - '0');
		input++;
	}
}


int main (int argc, char **argv)
{
	int num ;
	int prime ;
	int n;
	int t ;

	t = 2;
	n = 2;
	prime = 0;
	num = 0;
	if (argc == 2 && (argv[1][0] >= '0' || argv[1][0] <= '9') )
	{
		ft_atoi(&num,argv[1]);
		if (num < 0)
		{
			write(1,"\n",1);
			return(0);
		}

		while( n <= num )
		{
			while(t <= n )
			{ 
				if(t < n &&  n % t == 0)
					break;   		
				else if (n == t)
					prime = prime + n;
			t++;
			}	
			t = 2;	
			n++;
		}

		printf("%d",prime );

	}
	write(1,"\n",1);
	return(0);
}
