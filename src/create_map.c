/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:53:43 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/24 20:21:51 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void	parsing_map(t_mappy *sex, int fd)
{
	int	x;
	int	y;
	int	check_x;
	int	check_y;

	y = 0;
	sex->map[y] = NULL;
	while ((sex->map[y] = get_next_line(fd)) != NULL)
	{
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
	mlx_image_to_window(sex->mlx, sex->texture_array[4].image, check_x
		* TILE_SIZE, check_y * TILE_SIZE);
}

void	aff_map(t_mappy *sex, int fd, char *filename)
{
	int	nb_line;

	nb_line = ft_count_line_map(filename);
	sex->map = calloc(nb_line, (sizeof(char *)));
	parsing_map(sex, fd);
}
