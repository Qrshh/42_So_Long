/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:59:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/01 21:31:14 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void	event_listener(mlx_key_data_t press, void *param)
{
	t_mappy	*map;
	int		new_y;
	int		new_x;

	map = (t_mappy *)param;
	new_y = map->texture_array[4].image->instances->y;
	new_x = map->texture_array[4].image->instances->x;
	select_key(press, new_x, new_y, map);
	delete_img_collected(map);
}

void	generate_window(char *filename, int fd)
{
	static t_mappy	sex = {0};

	sex.mlx = mlx_init(WIDTH, HEIGHT, "GAME", true);
	if (!sex.mlx)
		exit_error("Window's not opening", NULL);
	initialize_textures(&sex);
	aff_map(&sex, fd, filename);
	check_path(&sex);
	mlx_loop_hook(sex.mlx, ft_hook, &sex);
	mlx_key_hook(sex.mlx, event_listener, &sex);
	mlx_loop(sex.mlx);
	mlx_terminate(sex.mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	static t_mappy all = {0};

	if (ac == 2)
	{
		all.filename = av[1];
		all.map = tab_map(av[1]);
		if (check_map(&all) == 1)
		{
			wall_checker(all.map);
			fd = open(all.filename, O_RDONLY);
			generate_window(all.filename, fd);
			close(fd);
		}
		else
			exit_error("Map is not compliant", all.map);
	}
	else
		exit_error("Arguments Problem", NULL);
	if (all.map)
		free_map(all.map);
	return (0);
}
