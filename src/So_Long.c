/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:59:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/16 23:24:53 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void	affMap(int fd, mlx_t *mlx, TextureInfo *textureArray)
{
	int		x;
	int		y;
	int		checkX;
	int		checkY;
	lamap	mapTest;

	y = 0;
	mapTest.mapp = malloc(ft_count_line_map("maps/map1.ber")
			* (sizeof(char *)));
	while ((mapTest.mapp[y] = get_next_line(fd)) != NULL)
	{
		x = 0;
		while (mapTest.mapp[y][x] != '\0')
		{
			select_image(mapTest, textureArray, x, y, mlx);
			if (mapTest.mapp[y][x] == 'P')
			{
				checkY = y;
				checkX = x;
			}
			x++;
		}
		y++;
	}
	free(mapTest.mapp);
	mlx_image_to_window(mlx, textureArray[4].image, checkX * TILE_SIZE, checkY
		* TILE_SIZE);
	recupTabMap(textureArray, mapTest);
}

int	main(void)
{
	int			fd;
	TextureInfo	textureArray[5];
	mlx_t		*mlx;

	// MLX allows you to define its core behaviour before startup
	mlx = mlx_init(WIDTH, HEIGHT, "TEST", true);
	// settings de la fenetre
	if (!mlx)
		ft_printf("%s", "la fenetre ne s'ouvre pas");
	fd = open("maps/map1.ber", O_RDONLY);
	initializeTextures(mlx, textureArray);
	affMap(fd, mlx, textureArray);
	close(fd);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
	