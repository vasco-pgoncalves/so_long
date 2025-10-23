/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:06:31 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/06 15:04:42 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* int main(void)
{
	printf("%d\n", ft_strncmp("apple", "apple", 5));
	printf("%d\n", ft_strncmp("apple", "apricot", 3));
	printf("%d\n", ft_strncmp("apple", "apPle", 5));
	printf("%d\n", ft_strncmp("app", "apple", 5));
	printf("%d\n", ft_strncmp("banana", "ban", 3));
	printf("%d\n", ft_strncmp("ban", "banana", 5));
	return 0;
} */
