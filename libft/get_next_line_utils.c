/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:37:15 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/06/06 15:35:11 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[j + i] = '\0';
	free(s1);
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
