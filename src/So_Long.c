/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:59:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/11 18:13:31 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void decla(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}


int32_t main(void)
{
    //MLX allows you to define its core behaviour before startup
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Suck My Balls", true); //settings de la fenetre
    if(!mlx)
        ft_printf("%s", "la fenetre ne s'ouvre pas");
    mlx_loop_hook(mlx, decla, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}



