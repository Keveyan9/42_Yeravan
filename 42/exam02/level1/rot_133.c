#include <unistd.h>

int main(int argc , char **argv)
{
	int n;

	n = 0;
	if (argc == 2)
	{
		while(argv[1][n])
		{
			argv[1][n] = ((argv[1][n] + 13 - 'a' )%26)+'a';
			write(1,&argv[1][n],1);
		n++;
		}
	}
	return(0);
}
