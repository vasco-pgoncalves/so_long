/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:37:29 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/07 13:52:25 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(long nbr);
static char		*mem_alloc(int len, long nbr);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = mem_alloc(len, nbr);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
	{
		result[0] = '-';
	}
	result[len] = '\0';
	return (result);
}

static char	*mem_alloc(int len, long nbr)
{
	char	*tmp;

	tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	if (nbr == 0)
	{
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	return (tmp);
}

static size_t	int_len(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	if (nbr == 0)
	{
		return (1);
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
/* int main ()
{
	printf("%s\n", ft_itoa(-274566));
} */