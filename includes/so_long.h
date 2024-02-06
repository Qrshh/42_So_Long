/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:01:57 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/06 00:10:23 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "Libft/inc/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 400
# define TILE_SIZE 16
# define EXTENSION ".ber"

typedef struct s_texture_info
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}					t_texture_info;

typedef struct s_info
{
	int				floor;
	int				collectibles;
	int				wall;
	int				exit;
	int hero;

}					t_info;

typedef struct s_player
{
	int				player_mouv;
	int				x;
	int				y;
}					t_player;

typedef struct s_map
{
	t_info			info;

	int				fd;

	int				map_width;
	int				map_height;

	int				items_collected;

	char			**matrix;

	t_texture_info	texture_array[7];
	mlx_t			*mlx;
}					t_map;

typedef struct s_game
{
	t_map			map;
	t_player		player;
	int				init;
}					t_game;

///////////////////////////////////////////////////////

// MAIN :
void				init_var(t_game *all);

// MAP HANDLER :
void				init_map(t_game *all);
int					len_map(char *str);

// ASSETS :
void				asset_init(t_game *all);

// DISPLAY :
void				display_assets(t_game *all);
void				display_floor(t_game *all, int x, int y);
void				display_wall(t_game *all, int x, int y);
void				display_collectible(t_game *all, int x, int y);
void				display_door(t_game *all, int x, int y);
void				display_hero(t_game *all, int x, int y);

// UTILS :
void				exit_error(char *msg, char **tab);
void				free_map(char **tab_map);
void				event_listener(mlx_key_data_t press, void *param);
void				select_key(mlx_key_data_t press, t_game *all);
void				delete_img_collected(t_game *all);

// PLAYER :
void				check_key(void *param);
int					check_move(t_game *all, int new_x, int new_y);
void				moove_update(t_game *all);
void				up(t_game *all);
void				down(t_game *all);
void				left(t_game *all);
void				right(t_game *all);

// MAP CHECKERS
void				check_map(t_game *all);

#endif
