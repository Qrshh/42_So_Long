/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:59:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/22 23:43:48 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void	aff_map(t_mappy *sex, int fd)
{
	int	x;
	int	y;
	int	check_x;
	int	check_y;

	sex->map = calloc(ft_count_line_map("maps/map1.ber"), (sizeof(char *)));
	y = 0;
	while ((sex->map[y] = get_next_line(fd)) != NULL)
	{
		printf("<%2d>%s", y, sex->map[y]);
		x = 0;
		while (sex->map[y][x] != '\0')
		{
			select_image(sex, x, y);
			if (sex->map[y][x] == 'P')
			{
				check_y = y;
				check_x = x;
			}
			x++;
		}
		y++;
	}
	printf("player: %d %d\n", check_x, check_y);
	mlx_image_to_window(sex->mlx, sex->texture_array[4].image, check_x
		* TILE_SIZE, check_y * TILE_SIZE);
}

int	main(void)
{
	static t_mappy	sex = {0};
	int				fd;

	if (checkMap("maps/map1.ber") == 0)
	{
		sex.mlx = mlx_init(WIDTH, HEIGHT, "TEST", true);
		if (!sex.mlx)
			ft_printf("%s", "la fenetre ne s'ouvre pas");
		fd = open("maps/map1.ber", O_RDONLY);
		initialize_textures(&sex);
		aff_map(&sex, fd);
		close(fd);
		mlx_loop_hook(sex.mlx, ft_hook, &sex);
		mlx_loop(sex.mlx);
		mlx_terminate(sex.mlx);
		return (0);
	}
	else
		ft_printf("%s\n", "La map n'est pas conforme");
}
