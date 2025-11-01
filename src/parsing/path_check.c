/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:26:42 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/11/01 16:21:45 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    path_check(t_data *data)
{
    int i;
    int len;
    t_position	player;
    
    if(!copy_map(data))
        return (0);
    player = P_finder(data);
    flood_fill(data, player.x, player.y);
    i = 0;
    while(data->map_cpy[i])
        {
            len = 0;
            while(data->map_cpy[i][len])
            {
                if(data->map_cpy[i][len] != '1' && data->map_cpy[i][len] != 'F')
                    return (0);
                len++;
            }
            i++;
        }
        return (1);
}
void flood_fill(t_data *data, int x, int y)
{
    if (x < 0 || y < 0 || y >= data->map_height || x >= data->map_len)
		return ;
    if (data->map_cpy[y][x] == '1' || data->map_cpy[y][x] == 'F')
        return ;
    data->map_cpy[y][x] = 'F';
    flood_fill(data, x + 1, y);
    flood_fill(data, x - 1, y);
    flood_fill(data, x, y + 1);
    flood_fill(data, x, y - 1);
}