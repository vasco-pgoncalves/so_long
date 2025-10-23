/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:43:31 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/06/06 15:31:27 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_newline_counter(char *line);
char	*ft_line_builder(char *s);
void	ft_clean_stash(char *stash);
char	*get_next_line(int fd);

#endif