/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:16:59 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/06 14:35:12 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (size > INT_MAX / nmemb)
	{
		return (NULL);
	}
	s = malloc(size * nmemb);
	if (!s)
		return (NULL);
	ft_bzero (s, (size * nmemb));
	return (s);
}
