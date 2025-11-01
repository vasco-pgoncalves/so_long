/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:12:48 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/07 16:20:13 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;

	if (size == 0)
		return (ft_strlen(src));
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (size <= destlen)
		return (srclen + size);
	else
		ft_strlcpy (&dest[destlen], src, (size - destlen));
	return (destlen + srclen);
}

/* int main()
{
char dest[] = "Badre";
char src[] = "AAAAAAAAA";
size_t size = 6;

size_t result = ft_strlcat(dest, src, size);
printf("%s\n%s\n", src, dest);
printf("Return value: %zu\n", result);
} */