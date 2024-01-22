/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SOLONG.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:01:57 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/22 23:43:16 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "Libft/inc/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
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

typedef struct s_mappy
{
	char			**map;
	mlx_t			*mlx;
	t_texture_info	texture_array[7];
}					t_mappy;

int					ft_count_line_map(char *fichier);
void				initialize_textures(t_mappy *map);
void				select_image(t_mappy *map, int x, int y);
void				ft_hook(void *param);
int					check_map(char *filename);

#endif