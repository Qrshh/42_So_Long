/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:47:35 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/05 22:42:49 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void right(t_game *all)
{
    int x;

    x = all->player.x + 16;
    if(check_move(all, x, all->player.y))
    {
        all->player.x = x;
        all->map.texture_array[4].image->instances[0].x = x;
        all->map.texture_array[4].image->instances[0].y = all->player.y;
        moove_update(all);
    }
}

void left(t_game *all)
{
    int x;

    x = all->player.x - 16;
    if(check_move(all, x, all->player.y))
    {
        all->player.x = x;
        all->map.texture_array[4].image->instances[0].x = x;
        all->map.texture_array[4].image->instances[0].y = all->player.y;
        moove_update(all);
    }
}

void down(t_game *all)
{
    int y;

    y = all->player.y + 16;
    if(check_move(all, all->player.x, y))
    {
        all->player.y = y;
        all->map.texture_array[4].image->instances[0].y = y;
        all->map.texture_array[4].image->instances[0].x = all->player.x;
        moove_update(all);
    }
}

void up(t_game *all)
{
    int y;

    y = all->player.y - 16;
    if(check_move(all, all->player.x, y))
    {
        all->player.y = y;
        all->map.texture_array[4].image->instances[0].y = y;
        all->map.texture_array[4].image->instances[0].x = all->player.x;
        moove_update(all);
    }
}