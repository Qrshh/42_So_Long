/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:45:48 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/17 12:34:10 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

int	ft_count_line_map(char *fichier)
{
	int	fd;
	int	i;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Erreur d'ouverture du fichier");
		return (-1);
	}
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

void	initializeTextures(mlx_t *mlx, TextureInfo *textureArray)
{
	int	i;

	i = 0;
	textureArray[0].texture = mlx_load_png("assets/wall_1.png");
	textureArray[1].texture = mlx_load_png("assets/floor_6.png");
	textureArray[2].texture = mlx_load_png("assets/barrel.png");
	textureArray[3].texture = mlx_load_png("assets/goblin_f0.png");
    textureArray[4].texture = mlx_load_png("assets/knight.png");
	while (i < 5)
	{
		textureArray[i].image = mlx_texture_to_image(mlx,
				textureArray[i].texture);
		mlx_delete_texture(textureArray[i].texture);
		i++;
	}
}

void	select_image(lamap Map, TextureInfo *textureArray, int x, int y,
		mlx_t *mlx)
{
	if (Map.mapp[y][x] == '1')
		mlx_image_to_window(mlx, textureArray[0].image, x * TILE_SIZE, y
			* TILE_SIZE);
	if (Map.mapp[y][x] == '0' || Map.mapp[y][x] == 'D' || Map.mapp[y][x] == 'M' || Map.mapp[y][x] == 'P')
		mlx_image_to_window(mlx, textureArray[1].image, x * TILE_SIZE, y
			* TILE_SIZE);
	if (Map.mapp[y][x] == 'D')
	{
		mlx_image_to_window(mlx, textureArray[2].image, x * TILE_SIZE, y
			* TILE_SIZE);
	}
	if (Map.mapp[y][x] == 'M')
	{
		mlx_image_to_window(mlx, textureArray[3].image, x * TILE_SIZE, y
			* TILE_SIZE);
	}
}

