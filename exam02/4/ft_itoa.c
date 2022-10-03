#include <stdlib.h>
#include<stdio.h>

char *ft_itoa(int nbr)
{
	int calemb;
	unsigned int box;
	char *readback;
	unsigned int box1;

	calemb = 2;
	if( nbr < 0 )
	{
		calemb++;
		box = nbr*-1;
	}
	else
		box = nbr;
	box1 = box;
	while(box > 9)
	{	calemb++;
		box  = box / 10;
	}
	readback = (char*)malloc(calemb--);
	if(!readback)
		return(NULL);
	readback[calemb--] = '\0';
	while(box1 > 9)
	{
		readback[calemb--] =box1%10 +'0';
		box1=box1/10;
	}
	readback[calemb--] =box1 + '0';
	if(calemb==0)
		readback[calemb] = '-';
	return(readback);
}

int main ()
{
	printf("%s",ft_itoa(0));
			return(0);
}
