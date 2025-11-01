/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:39:49 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/11/01 16:23:50 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void    error_function(int error_nb, t_data **data)
{
    (void)data;
    
    if (error_nb == 1)
        printf("error1: rows have diferrent size\n");
    if (error_nb == 2)
        printf("error2: missing walls\n");
    if (error_nb == 3)
        printf("error3: missing elements\n");
    if (error_nb == 4)
        printf("error4: unwanted elements\n");
    if (error_nb == 5)
        printf("error5: invalid path\n");
        
    exit(1);
} 