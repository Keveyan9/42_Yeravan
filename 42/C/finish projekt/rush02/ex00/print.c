/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidavtya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:20:25 by tidavtya          #+#    #+#             */
/*   Updated: 2022/02/20 18:53:40 by tidavtya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		zero_case(char **argv);
int		str_len(char *str);
void	put_word(char *str);
void	put_ex(int max_numar, char triplet[3]);
void	parse_dict(void);
void	parse_input(char *input);

char	g_dict_data[2048];
char	g_parsed_dict[41][12];
char	g_parsed_input[13][4];

void	print_first_digit(char triplet[3])
{
	if (triplet[0] > '0')
	{
		put_word(g_parsed_dict[triplet[0] - '0']);
		write (1, "hundred ", 8);
	}
}

void	print_triplet(int max_num, char triplet[3])
{
	print_first_digit(triplet);
	if (triplet[1] == '1')
	{
		put_word(g_parsed_dict[10 + (triplet[2] - '0')]);
		put_ex(max_num, triplet);
		return ;
	}
	else if (triplet[1] == '0' && triplet[2] != '0')
	{
		put_word(g_parsed_dict[triplet[2] - '0']);
		put_ex(max_num, triplet);
		return ;
	}
	else if (triplet[1] == '0' && triplet[2] == '0')
	{
		put_ex(max_num, triplet);
		return ;
	}
	else
		put_word (g_parsed_dict[20 + (triplet[1] - '0' - 2)]);
	if (triplet[2] != '0')
		put_word (g_parsed_dict[triplet[2] - '0']);
	if (max_num != 0)
		put_word (g_parsed_dict[28 + max_num]);
}

void	print_nums(int max_num, char **argv, int i)
{
	parse_dict();
	if (zero_case (argv))
		return ;
	parse_input(argv[1]);
	i = 0;
	if (str_len(argv[1]) >= 3)
	{
		if (max_num % 3 != 0)
			max_num = (max_num / 3) + 1;
		else
			max_num /= 3;
	}
	else
	{
		max_num = 0;
		print_triplet(max_num, g_parsed_input[i]);
	}
	while (--max_num >= 0)
	{
		print_triplet(max_num, g_parsed_input[i]);
		i++;
	}
}
