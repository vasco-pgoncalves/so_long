/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:37:15 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/11/01 16:33:13 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	ft_newline_counter(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, s1_len + 1);
	ft_strlcat(s3, s2, s1_len + s2_len + 1);
	return (s3);
}

char	*ft_line_builder(char *s)
{
	int	i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			s[i + 1] = '\0';
			break ;
		}
		i++;
	}
	return (s);
}

void	ft_clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	int		new_start;

	new_start = ft_newline_counter(stash);
	if (new_start == -1)
	{
		stash[0] = '\0';
		return ;
	}
	i = new_start + 1;
	j = 0;
	while (stash[i])
		stash[j++] = stash[i++];
	stash[j] = '\0';
	return ;
}
