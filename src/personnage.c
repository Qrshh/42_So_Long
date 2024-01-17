/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personnage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:23:24 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/17 17:32:44 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"


static TextureInfo txtArray[1];
static lamap Map;
void recupTabMap(TextureInfo *textureArray, lamap MapEnvoi)
{
    txtArray[0] = textureArray[4];
    Map = MapEnvoi;
}

int isValid(lamap Map, int x, int y)
{
    int mapX = x / 16;
    int mapY = y / 16;
    if(Map.mapp[mapY][mapX] == '0')
        return (1);
    return (0);
}

void select_key(mlx_t *param, int newX, int newY)
{
    if(mlx_is_key_down(param, MLX_KEY_W))
    {
        if(isValid(Map, newX, newY - 16) == 1)
            txtArray[0].image->instances[0].y = newY - 16;
    }
    if(mlx_is_key_down(param, MLX_KEY_S))
    {
        if(isValid(Map, newX, newY + 16) == 1)
            txtArray[0].image->instances[0].y = newY + 16;
    }
    if(mlx_is_key_down(param, MLX_KEY_D))
    {
        if(isValid(Map, newX + 16, newY) == 1)
            txtArray[0].image->instances[0].x = newX + 16;
    }
    if(mlx_is_key_down(param, MLX_KEY_A))
    {
        if(isValid(Map, newX - 16, newY) == 1)
            txtArray[0].image->instances[0].x = newX - 16;
    }
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

    int newY = txtArray[0].image->instances->y;
    int newX = txtArray[0].image->instances->x;
    
	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
    select_key(param, newX, newY);
}
