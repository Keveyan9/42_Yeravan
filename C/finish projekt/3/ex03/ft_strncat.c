/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 03:46:14 by skeveyan          #+#    #+#             */
/*   Updated: 2022/02/22 04:21:52 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	n;
	unsigned int	i;

	n = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[n] && nb != 0)
	{
		dest[i++] = src[n++];
		nb--;
	}
	dest[i] = '\0';
	return (dest);
}
