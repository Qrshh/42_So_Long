/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:30:52 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/07 23:05:57 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handler_error(int ac, char **av);

int	main(int ac, char **av)
{
	t_game	all;

	handler_error(ac, av);
	init_var(&all);
	all.map.fd = open(av[1], O_RDONLY);
	init_map(&all);
	all.map.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	asset_init(&all);
	display_assets(&all);
	check_map(&all);
	mlx_loop_hook(all.map.mlx, check_key, &all);
	mlx_key_hook(all.map.mlx, event_listener, &all);
	mlx_loop(all.map.mlx);
	destroy_window(&all);
	free_map(all.map.matrix);
	return (0);
}

void	init_var(t_game *all)
{
	all->init = 1;
	all->map.fd = 0;
	all->map.matrix = NULL;
	all->map.map_height = 0;
	all->map.map_width = 0;
	all->player.player_mouv = 0;
	all->player.x = 0;
	all->player.y = 0;
	all->map.items_collected = 0;
	all->map.info.collectibles = 0;
	all->map.info.wall = 0;
	all->map.info.floor = 0;
	all->map.info.exit = 0;
	all->map.info.hero = 0;
}

void	check_key(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
}

static void	handler_error(int ac, char **av)
{
	if (ac != 2)
		exit_error("Args Problem", NULL);
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
		exit_error("Error \nWrong extension for map", NULL);
}
