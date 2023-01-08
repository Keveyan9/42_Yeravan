/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:18:35 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/21 13:35:31 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcapitalize(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (((str[n] >= 'a' && str[n] <= 'z')
				|| (str[n] >= 'A' && str[n] <= 'Z')
				|| (str[n] >= '0' && str[n] <= '9')))
		{
			if (str[n] >= 'a' && str[n] <= 'z')
				str[n] = str[n] - 32;
			n++;
			while (((str[n] >= 'a' && str[n] <= 'z')
					|| (str[n] >= 'A' && str[n] <= 'Z')
					|| (str[n] >= '0' && str[n] <= '9')))
			{
				if (str[n] >= 'A' && str[n] <= 'Z')
					str[n] = str[n] + 32;
				n++;
			}
		}
	n++;
	}
	return (str);
}
