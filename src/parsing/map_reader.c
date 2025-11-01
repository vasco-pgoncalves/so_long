/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:52:49 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/11/01 16:16:24 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(int fd, t_data *data)
{
    char *line;
    char *line_accumulator = NULL;

    while ((line = get_next_line(fd)) != NULL)
    {
        if (line_accumulator == NULL)
            line_accumulator = ft_strdup(line);
        else
            line_accumulator = ft_strjoin(line_accumulator, line);

        free (line);
    }
    
	if (!line_accumulator)
		error_function(2, &data);

	if (!new_line_check(line_accumulator))
	{
		free(line_accumulator);
		error_function(3, &data);
	}
	data->map = ft_split(line_accumulator, '\n');
	free(line_accumulator);
	map_error(data);
}
int copy_map(t_data *data)
{
    int i;

    i = 0;
    data->map_cpy = malloc(sizeof(char*) * (data->map_height + 1));
    if(!data->map_cpy)
        return (0);
    while (i < data->map_height)
    {
        data->map_cpy[i] = ft_strdup(data->map[i]);
            if(!data->map_cpy[i])
                return (0);
        i++;
    }
	data->map_cpy[i] = NULL;
	return (1);
}
t_position P_finder(t_data *data)
{
    t_position player;
    int x;
    int y;
    x = 0;
    y = 0;

    while (data->map[y])
    {
        x = 0;
        while(data->map[y][x])
        {
            if (data->map[y][x] == 'P')
            {
                player.x = x;
                player.y = y;
                return (player);
            }
            x++;
        }
        y++;
    }
    player.x = -1;
    player.y = -1;
    return (player);
}
t_position E_finder(t_data *data)
{
    t_position exit;
    int x;
    int y;
    x = 0;
    y = 0;

    while (data->map[y])
    {
        x = 0;
        while(data->map[y][x])
        {
            if (data->map[y][x] == 'E')
            {
                exit.x = x;
                exit.y = y;
                return (exit);
            }
            x++;
        }
        y++;
    }
    exit.x = -1;
    exit.y = -1;
    return (exit);
}
void    map_error(t_data *data)
{
    if (!shape_check(data))
        error_function (1, &data);
    if (!wall_checker(data))
        error_function (2, &data);
    if (!elements_check(data, 0, 0, 0))
        error_function (3, &data);
    if (!valid_char(data))
        error_function (4, &data);
    if (!path_check(data))
        error_function (5, &data);
}