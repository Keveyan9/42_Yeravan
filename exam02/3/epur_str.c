#include <unistd.h>

int main (int argc, char **argv)
{
	int flag;
	int n;

	n = 0; 
	flag = 0;
	if (argc == 2)
	{

		while(argv[1][n] =='\t' || argv[1][n] == ' ')
			n++;
		while(argv[1][n])
		{
			if (argv[1][n] == '\t' || argv[1][n] == ' ')
				flag = 1;
			while(argv[1][n] =='\t' || argv[1][n] == ' ')
				n++;
			if(flag == 1 && argv[1][n])
			{
				write(1," " ,1);
				flag = 0;
			}
			if (argv[1][n])
				write(1,&argv[1][n++],1);

		}
	}
	write(1,"\n",1);
	return(0);
}
