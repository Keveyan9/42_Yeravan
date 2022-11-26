#include"unistd.h"
#include "stdio.h"

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
int main()
{
	int n = 5;
	printf("%d\n",n);
	 n= n >> 6  ;
	printf("%d\n",n);
//	print_bits(5);
}

