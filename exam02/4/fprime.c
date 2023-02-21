#include<stdio.h>
#include<stdlib.h>

int main (int argc ,char **argv)
{
	int input;
	int devider;
	char flag;

	flag = 0;
	input = 0;
	devider = 2;
	if (argc == 2)
	{
		input = atoi(argv[1]);
		if (input == 1)
			printf("1");
		while(input > 1)
		{
			if(input%devider==0)
			{	
				if (flag != 0)
					printf("*");
				printf("%d",devider);
				input = input/devider;
				devider = 1;
				flag = 1 ;
			}
			devider ++;
		}
	}
	else 
		printf("\n");
	return(0);
}
	
