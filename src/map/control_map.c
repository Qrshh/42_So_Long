/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:59:01 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/05 23:19:07 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_shape(t_game *all)
{
	int	i;
	int len;
	
	i = 1;
	len = ft_strlen(all->map.matrix[0]);
	while(all->map.matrix)
	{
		if(len != (int)ft_strlen(all->map.matrix[i]))
		{
			exit_error("Map is not rectangular", NULL);
		}
		i++;
	}
	return (1);
}

void check_map(t_game *all)
{
    if(!check_shape(all))
        exit_error("La map n'est pas conforme", NULL);
}