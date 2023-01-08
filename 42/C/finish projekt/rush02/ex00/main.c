/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidavtya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:59:17 by tidavtya          #+#    #+#             */
/*   Updated: 2022/02/20 21:08:03 by tidavtya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void	parse_helper2(int indices[3], char *input);
void	parse_helper1(char *input, int indices[3], int size);
void	parse_input(char *input);
void	parse_dict(void);
void	print_first_digit(char triplet[3]);
void	print_triplet(char triplet[3], int max_num);
void	print_nums(int max_num, char **argv, int i);

char	g_dict_data[2048];
char	g_parsed_dict[41][12];
char	g_parsed_input[13][4];

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	put_word(char *str);
void	put_ex(int max_num);

int	zero_case(char **argv)
{
	if (str_len(argv[1]) == 1)
	{
		if (argv[1][0] == '0')
		{
			put_word (g_parsed_dict[0]);
			return (1);
		}
	}
	return (0);
}

int	invalid_input(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 2)
		return (1);
	if (str_len(argv[1]) > 39)
		return (1);
	while (argv[1][++i] != '\0')
	{
		if (argv[1][i] > '9' || argv[1][i] < '0')
			return (1);
	}
	return (0);
}

int	errors(int dict, int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "No input", 8);
		return (1);
	}
	if (dict == -1)
	{
		write (1, "Dict Error", 10);
		return (1);
	}
	if (invalid_input(argc, argv))
	{
		write (1, "Invalid Input", 13);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		happy_norme[4];
	char	t[1];
	int		dict;

	happy_norme[1] = 0;
	dict = open("numbers.dict", O_RDONLY);
	if (errors(dict, argc, argv))
		return (1);
	happy_norme[0] = -1;
	happy_norme[3] = -1;
	read(dict, t, 1);
	while (++happy_norme[3] < 700)
	{
		read(dict, t, 1);
		g_dict_data[++happy_norme[0]] = t[0];
	}
	close(dict);
	happy_norme[2] = str_len(argv[1]);
	print_nums(happy_norme[2], argv, happy_norme[1]);
	return (0);
}
