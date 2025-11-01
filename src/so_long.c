/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 12:52:43 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/11/01 16:39:39 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "so_long.h"

int main(void)
{
    t_data *data;

    data = malloc(sizeof(t_data));
        if (!data)
        return (1);
    ft_memset(data, 0, sizeof(t_data));
} */
#include "so_long.h"

int main(int argc, char *argv[])
{
    int     fd;
    t_data  *data;

    if (argc != 2)
    {
        printf("Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return (1);
    }

    data = malloc(sizeof(t_data));
    if (!data)
        return (1);
    data->map = NULL;
    data->map_cpy = NULL;
    data->map_height = 0;
    data->map_len = 0;

    read_map(fd, data);
    close(fd);

    map_error(data);

    printf("Map parsing successful!\n");

    /* Free memory */
    for (int i = 0; i < data->map_height; i++)
    {
        free(data->map[i]);
        free(data->map_cpy[i]);
    }
    free(data->map);
    free(data->map_cpy);
    free(data);

    return (0);
}