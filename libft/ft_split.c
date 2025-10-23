/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:54:00 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/05/07 16:23:07 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_filler(const char *s, char c)
{
	size_t	size;
	char	*s2;

	size = 0;
	while (s[size] != c && s[size] != '\0')
		size++;
	s2 = ft_calloc(sizeof(char), size + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy (s2, s, size + 1);
	return (s2);
}

static void	ft_free(char **ar)
{
	size_t	i;

	i = 0;
	if (!ar)
		return ;
	while (ar[i])
	{
		free (ar[i]);
		i++;
	}
	free (ar);
}

static char	**ft_sepword(char **a, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			a[j] = ft_filler(&s[i], c);
			if (!a[j++])
			{
				ft_free (a);
				return (NULL);
			}
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**ar;

	if (!s)
		return (NULL);
	ar = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (!ar)
		return (NULL);
	ft_sepword (ar, s, c);
	return (ar);
}

// int main(void)
// {
//     char **tab;
//     int i;

//     i = 0;
//     tab = ft_split("", ' ');
//     while (tab[i] != NULL)
//     {
//         printf("%s\n", tab[i]);
//         i++;
//     }

//     i = 0;
//     while (tab[i] != NULL)
//     {
//         free(tab[i]);
//         i++;
//     }
//     free(tab);

//     return 0;
// }
