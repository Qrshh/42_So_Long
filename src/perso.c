/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:23:24 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/24 23:24:45 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

void delete_img_collected(t_mappy *sex)
{
	size_t i;
	size_t nb_items;

	nb_items = sex->texture_array[5].image->count;
	i = 0;
	
	while(i < nb_items)
	{
		if(sex->texture_array[5].image->instances[i].x == sex->texture_array[4].image->instances[0].x && sex->texture_array[5].image->instances[i].y == sex->texture_array[4].image->instances[0].y)
			sex->texture_array[5].image->instances[i].enabled = false;
		i++;
	}
}

int	is_valid(char **map, int x, int y, t_mappy *sex)
{
	int			map_x;
	int			map_y;
	static int	count = 0;
	int			nb_items;

	nb_items = sex->texture_array[5].image->count;
	if (x < 0 || y < 0)
		return (0);
	map_x = x / 16;
	map_y = y / 16;
	if (map[map_y][map_x] == 'C' && count < nb_items)
	{
		count++;
		ft_printf("%d", count);
		map[map_y][map_x] = '0';
		return (1);
	}
	else if (map[map_y][map_x] == '0' || map[map_y][map_x] == 'P'|| map[map_y][map_x] == 'C')
		return (1);
	if (map[map_y][map_x] == 'E' && count == nb_items)
		mlx_close_window(sex->mlx);
	return (0);
}

void	ft_hook(void *param)
{
	t_mappy	*sex;

	sex = (t_mappy *)param;
	if (mlx_is_key_down(sex->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(sex->mlx);
}
