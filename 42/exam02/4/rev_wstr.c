#include<unistd.h>
#include<stdio.h>

int lengt(char *str)
	{
		int n = 0;

		while(str[n])
			n++;
		return(n);
	}

int main (int argc,char **argv)
{
	int lenqtvalu;
	int wordlenqt = 0;
	int manlenqtvalu;
	int flag = 0;

	if( argc == 2 )
	{
		lenqtvalu = lengt(argv[1]) - 1 ;
		while(lenqtvalu >= 0)
		{
			while(argv[1][lenqtvalu] != ' ' && argv[1][lenqtvalu] != '\t' && lenqtvalu >=0 )
			{
				lenqtvalu--;
				wordlenqt++;
			}
				manlenqtvalu = lenqtvalu;
				if(flag == 1)
					write(1," ",1);
			while(lenqtvalu >= -1 && wordlenqt > 0)
			{
				
				write(1,&argv[1][++lenqtvalu],1);
				wordlenqt--;

			}
			flag = 1;

					lenqtvalu =  manlenqtvalu - 1;
		}
	}
	else 
		write(1,"\n",1);
	return(0);
}

