/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:53:43 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/30 20:35:10 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void	parsing_map(t_mappy *sex, int fd)
{
	int	x;
	int	y;

	y = 0;
	sex->map[y] = get_next_line(fd);
	while (sex->map[y] != NULL)
	{
		x = 0;
		while (sex->map[y][x] != '\0')
		{
			select_image(sex, x, y);
			if (sex->map[y][x] == 'P')
			{
				sex->player_y = y;
				sex->player_x = x;
			}
			x++;
		}
		y++;
		sex->map[y] = get_next_line(fd);
	}
	mlx_image_to_window(sex->mlx, sex->texture_array[4].image, sex->player_x
		* TILE_SIZE, sex->player_y * TILE_SIZE);
}

void	aff_map(t_mappy *sex, int fd, char *filename)
{
	int	nb_line;

	nb_line = ft_count_line_map(filename) + 1;
	sex->map = calloc(1, (sizeof(char *) * nb_line));
	parsing_map(sex, fd);
}
