/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 04:25:00 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/22 05:44:13 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (!*to_find)
		return (str);
	while (str[n])
	{
		while (str[n + i] == to_find[i])
		{
			if (!to_find[i + 1])
				return (&str[n]);
			i++;
		}
		i = 0;
		n++;
	}
	return (0);
}
