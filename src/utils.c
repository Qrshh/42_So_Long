/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:36:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/08 21:12:09 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **tab_map)
{
	int	i;

	i = 0;
	while (tab_map[i])
	{
		free(tab_map[i]);
		i++;
	}
	free(tab_map);
}

void	exit_error(char *msg, char **tab)
{
	if (tab != NULL)
		free_map(tab);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	event_listener(mlx_key_data_t press, void *param)
{
	t_game	*all;

	all = (t_game *)param;
	select_key(press, all);
	delete_img_collected(all);
}

void	select_key(mlx_key_data_t press, t_game *all)
{
	if (press.key == MLX_KEY_D && press.action == MLX_RELEASE)
		right(all);
	else if (press.key == MLX_KEY_A && press.action == MLX_RELEASE)
		left(all);
	else if (press.key == MLX_KEY_W && press.action == MLX_RELEASE)
		up(all);
	else if (press.key == MLX_KEY_S && press.action == MLX_RELEASE)
		down(all);
}

void	destroy_window(t_game *all)
{
	mlx_terminate(all->map.mlx);
}
