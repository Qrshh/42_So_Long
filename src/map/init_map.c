/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:17:21 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/06 00:57:40 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *all)
{
	char	*gnl;
	int		i;

	i = 0;
	gnl = get_next_line(all->map.fd);
	all->map.matrix = ft_calloc(1, sizeof(char *) * len_map(gnl));
	all->map.map_width = len_map(gnl);
	while (gnl != NULL)
	{
		all->map.matrix[i] = gnl;
		gnl = get_next_line(all->map.fd);
		i++;
	}
	all->map.matrix[i] = NULL;
	all->map.map_height = i;
}
