/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:16:58 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/06 14:57:36 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
/* int main (void)
{
	int c = '\0';
	const char *s = "\0";

	printf("%s", ft_strchr(s, c));
} */