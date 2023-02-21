/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidavtya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:52:19 by tidavtya          #+#    #+#             */
/*   Updated: 2022/02/20 17:18:17 by tidavtya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str);
char	g_dict_data[2048];
char	g_parsed_dict[41][12];
char	g_parsed_input[13][4];

void	parse_helper2(int indices[3], char *input)
{
	while (input[indices[0]] != '\0')
	{
		indices[1] = -1;
		while (++indices[1] < 3)
		{
			g_parsed_input[indices[2]][indices[1]] = input[indices[0]];
			indices[0]++;
		}
		indices[2]++;
	}
}

void	parse_helper1(char *input, int indices[3], int size)
{
	if (size % 3 == 2)
	{
		g_parsed_input[indices[2]][++indices[1]] = '0';
		g_parsed_input[indices[2]][++indices[1]] = input[indices[0]];
		g_parsed_input[indices[2]][++indices[1]] = input[++indices[0]];
		indices[2]++;
		indices[0]++;
	}
	else if (size % 3 == 1)
	{
		g_parsed_input[indices[2]][++indices[1]] = '0';
		g_parsed_input[indices[2]][++indices[1]] = '0';
		g_parsed_input[indices[2]][++indices[1]] = input[indices[0]];
		indices[2]++;
		indices[0]++;
	}
	parse_helper2(indices, input);
}

void	parse_input(char *input)
{
	int	size;
	int	indices[3];

	indices[0] = 0;
	indices[1] = -1;
	indices[2] = 0;
	size = str_len(input);
	parse_helper1(input, indices, size);
}

void	parse_dict(void)
{
	int	data_i;
	int	parsed_i;
	int	parsed_elem;

	data_i = -1;
	parsed_i = 0;
	parsed_elem = -1;
	while (g_dict_data[++data_i] != '\0' && parsed_i < 41)
	{
		if (g_dict_data[data_i] >= 'a' && g_dict_data[data_i] <= 'z')
			g_parsed_dict[parsed_i][++parsed_elem] = g_dict_data[data_i];
		if (g_dict_data[data_i] == '\n')
		{
			parsed_i++;
			parsed_elem = -1;
		}
	}
}
