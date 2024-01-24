/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:45:48 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/24 20:20:44 by abesneux         ###   ########.fr       */
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
		exit_error("Erreur d'ouverture du fichier contenant la map");
		return (-1);
	}
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

void	initialize_textures(t_mappy *sex)
{
	int	i;

	sex->texture_array[0].texture = mlx_load_png("assets/wall_1.png");
	sex->texture_array[1].texture = mlx_load_png("assets/floor_6.png");
	sex->texture_array[2].texture = mlx_load_png("assets/barrel.png");
	sex->texture_array[3].texture = mlx_load_png("assets/goblin_f0.png");
	sex->texture_array[4].texture = mlx_load_png("assets/knight.png");
	sex->texture_array[5].texture = mlx_load_png("assets/potion_yellow.png");
	sex->texture_array[6].texture = mlx_load_png("assets/exit.png");
	i = 0;
	while (i < 7)
	{
		sex->texture_array[i].image = mlx_texture_to_image(sex->mlx,
				sex->texture_array[i].texture);
		if (!sex->texture_array[i].image)
			exit_error("Erreur image");
		mlx_delete_texture(sex->texture_array[i].texture);
		i++;
	}
}

void	select_image(t_mappy *sex, int x, int y)
{
	if (sex->map[y][x] == '1')
		mlx_image_to_window(sex->mlx, sex->texture_array[0].image, x
			* TILE_SIZE, y * TILE_SIZE);
	if (sex->map[y][x] == '0' || sex->map[y][x] == 'D' || sex->map[y][x] == 'M'
		|| sex->map[y][x] == 'P' || sex->map[y][x] == 'C')
		mlx_image_to_window(sex->mlx, sex->texture_array[1].image, x
			* TILE_SIZE, y * TILE_SIZE);
	if (sex->map[y][x] == 'D')
		mlx_image_to_window(sex->mlx, sex->texture_array[2].image, x
			* TILE_SIZE, y * TILE_SIZE);
	if (sex->map[y][x] == 'M')
		mlx_image_to_window(sex->mlx, sex->texture_array[3].image, x
			* TILE_SIZE, y * TILE_SIZE);
	if (sex->map[y][x] == 'E')
		mlx_image_to_window(sex->mlx, sex->texture_array[6].image, x
			* TILE_SIZE, y * TILE_SIZE);
	if (sex->map[y][x] == 'C')
		mlx_image_to_window(sex->mlx, sex->texture_array[5].image, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	exit_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
