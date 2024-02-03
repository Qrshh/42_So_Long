/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:01:57 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/03 01:43:31 by abesneux         ###   ########.fr       */
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

typedef struct s_text_info
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}					t_texture_info;

typedef struct s_player
{
	int				player_mouv;
	int				x;
	int				y;
}					t_player;

typedef struct s_map
{
	int				fd;

	int				map_width;
	int				map_height;

	char			**matrix;
	char			*filename;

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

// UTILS :
void				exit_error(char *msg, char **tab);
void				free_map(char **tab_map);

// PLAYER :
void				check_key(void *param);

#endif
