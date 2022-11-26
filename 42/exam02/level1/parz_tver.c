#include <unistd.h>

int is_prime(int num)
{
	int i = 3;
	
	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return (0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}


int	ft_atoi(char *str)
{
	int n = 0;

	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}
int main(int argc, char *argv[])
{
	int sum = 0;
	int nb = ft_atoi(argv[1]);
	
	if (argc == 2)
	{
		while (nb > 0)
			if (is_prime(nb--))
				sum += (nb + 1);
		ft_putnbr(sum);
	}
	if (argc != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
