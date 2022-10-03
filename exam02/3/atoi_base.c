#include<stdio.h>
int  chekin (char c, int base)
{
	int n = 0;
	char shablon [ ] = "0123456789abcdef";
	if (c >= 'A' && c <= 'F')
		c = c + 32;	
	//printf("&&--%c--&&",c);
	while (n < base) 
	{
		if(shablon[n] == c)
			return(n);
		n++;
	}
		return(-1);
}

int ft_atoi_base(const char *str ,int str_base)
{
	int nshan ;
	int t ;
	int result;
	int  chekin_valu;

	t = 0;
	nshan = 1;
	result = 0;
	chekin_valu = 0;
	if (str[t]=='-')
	{
		nshan = -1;
		t++;
	}
	//printf("___%c__",str[t]);
	while(( chekin_valu = chekin(str[t++],str_base))  >= 0)
	{
		result = result * str_base + chekin_valu;	
	//printf("___%d__",chekin_valu);
	}
	return(result * nshan);
}

int main ()
{
	printf("%d", ft_atoi_base("-ff", 16));
}

