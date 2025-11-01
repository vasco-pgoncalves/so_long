/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:34:45 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/06/09 15:18:36 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				counter;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (*buf != '\0')
		line = ft_strjoin (line, buf);
	while (ft_newline_counter(line) == -1)
	{
		counter = read (fd, buf, BUFFER_SIZE);
		if (counter < 0)
		{
			buf[0] = '\0';
			return (free(line), NULL);
		}
		if (counter == 0)
			break ;
		buf[counter] = '\0';
		line = ft_strjoin(line, buf);
	}
	line = ft_line_builder(line);
	ft_clean_stash(buf);
	return (line);
}
/* int main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);

	while (line)
	{
		printf("/%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
} */