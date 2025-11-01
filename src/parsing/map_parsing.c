/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:52:57 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/11/01 16:20:50 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shape_check(t_data *data)
{
    size_t len;
    int i;
    i = 1;
    len = ft_strlen (data->map[0]);
    while (data->map[i])
    {
        if(ft_strlen(data->map[i]) != len)
        {
            return (0);
        }
        i++;
    }

    data->map_height = i;
    data->map_len = len;

        return (1);
}
int wall_checker(t_data *data)
{
    int len;
    int i;
    len = 0;
    i = 1;

    while (len < data->map_len)
    {
        if (data->map[0][len] != '1')
            return (0);
        len++;
    }
    while (i < data->map_height - 1)
    {
        if(data->map[i][0] != '1' || data->map[i][data->map_len - 1] != '1')
            return (0);
        i++;
    }
    i = data->map_height - 1;
    len = -1;
    while (++len < data->map_len)
         if (data->map[i][len] != '1')
            return (0);
    return (1);
}
int	elements_check(t_data *data, int coin, int exit, int player)
{
    int len;
    int i;
    i = 0;
    len = 0;
    
    while (data->map[i])
    {
        len = 0;
        while (data->map[i][len])
        {
            if (data->map[i][len] == 'E')
                exit++;
            if (data->map[i][len] == 'P')
                player++;
            if(data->map[i][len] == 'C')
                coin++;
            len++;
        }
        i++;
    }
    if (exit != 1 || player != 1 || coin < 1)
        return (0);
    return (1);
}
int valid_char(t_data *data)
{
    int len;
    int i;
    i = 0;
    len = 0;
    
    while (data->map[i])
    {
        len = 0;
        while (data->map[i][len])
        {
            if (data->map[i][len] != '1' && data->map[i][len] != '0' &&
                data->map[i][len] != 'E' && data->map[i][len] != 'P' &&
                data->map[i][len] != 'C')
                return (0);
            len++;
        }
        i++;
    }
    return (1);
}

