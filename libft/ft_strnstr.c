/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:38:09 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/07 15:25:29 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0] && i + ft_strlen(little) <= len)
		{
			if (ft_memcmp(&big[i], little, ft_strlen(little)) == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
