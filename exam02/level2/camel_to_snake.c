#include<unistd.h>

int main(int argc, char **argv)
{
	int n;

	n = 0;
	if(argc == 2)
	{
		while(argv[1][n])
		{
			if(argv[1][n] > 64 && argv[1][n] < 91)
			{
				write(1,"_",1);
				argv[1][n] = argv[1][n] + 32;
			}
			write(1,&argv[1][n],1);
			n++;
		}
	}
	write(1,"\n",1);
	return(0);
}
