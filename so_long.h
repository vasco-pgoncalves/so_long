/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:37:39 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/11/01 16:04:08 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "src/libft/libft.h"
# include "src/libft/get_next_line.h"

typedef struct s_data
{
    char    **map;
    char    **map_cpy;
    int     map_height;
    int     map_len;
}   t_data;
typedef struct s_position
{
    int    x;
    int    y;
}   t_position;


/* Parsing & map checks */
void        read_map(int fd, t_data *data);
int         new_line_check(char *s);
int         shape_check(t_data *data);
int         wall_checker(t_data *data);
int         elements_check(t_data *data, int coin, int exit, int player);
int         valid_char(t_data *data);
int         copy_map(t_data *data);
t_position  P_finder(t_data *data);
t_position  E_finder(t_data *data);
int         path_check(t_data *data);
void        flood_fill(t_data *data, int x, int y);

/* Error handling */
void        map_error(t_data *data);
void        error_function(int error_nb, t_data **data);

#endif