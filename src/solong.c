/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:59:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/24 23:25:18 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void event_listener(mlx_key_data_t press, void *param)
{
	t_mappy *map;
	map = (t_mappy *)param;
	int		new_y;
	int		new_x;

	new_y = map->texture_array[4].image->instances->y;
	new_x = map->texture_array[4].image->instances->x;
	if(press.key == MLX_KEY_D && press.action == MLX_RELEASE)
	{
		if (is_valid(map->map, new_x + TILE_SIZE, new_y, map) == 1)
			map->texture_array[4].image->instances[0].x = new_x + TILE_SIZE;
	}
	else if(press.key == MLX_KEY_A && press.action == MLX_RELEASE)
	{
		if (is_valid(map->map, new_x - TILE_SIZE, new_y, map) == 1)
			map->texture_array[4].image->instances[0].x = new_x - TILE_SIZE;
	}
	else if(press.key == MLX_KEY_W && press.action == MLX_RELEASE)
	{
		if (is_valid(map->map, new_x , new_y - TILE_SIZE, map) == 1)
			map->texture_array[4].image->instances[0].y = new_y - TILE_SIZE;
	}
	else if(press.key == MLX_KEY_S && press.action == MLX_RELEASE)
	{
		if (is_valid(map->map, new_x, new_y + TILE_SIZE, map) == 1)
			map->texture_array[4].image->instances[0].y = new_y + TILE_SIZE;
	}
	delete_img_collected(map);
}

void	generate_window(char *filename, int fd)
{
	static t_mappy	sex = {0};

	sex.mlx = mlx_init(WIDTH, HEIGHT, "GAME", true);
	if (!sex.mlx)
		exit_error("La fenetre ne s'ouvre pas");
	initialize_textures(&sex);
	aff_map(&sex, fd, filename);
	mlx_loop_hook(sex.mlx, ft_hook, &sex);
	mlx_key_hook(sex.mlx, event_listener, &sex);
	mlx_loop(sex.mlx);
	mlx_terminate(sex.mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*filename;
	char	**tab;

	if (ac == 2)
	{
		filename = av[1];
		tab = tab_map(av[1]);
		if (check_map(filename, tab) == 1)
		{
			fd = open(filename, O_RDONLY);
			generate_window(filename, fd);
			close(fd);
		}
		else
			exit_error("La map n'est pas conforme");
	}
	else
		exit_error("Probleme d'arguments");
	return (0);
}


