/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SOLONG.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:01:57 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/30 20:10:26 by abesneux         ###   ########.fr       */
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

typedef struct s_mappy
{
	char			**map;
	mlx_t			*mlx;
	t_texture_info	texture_array[7];
	int				player_count;
	int				exit_count;
	int				collectible_count;
	int				total_collectible;
	int				mouvement_count;
	int				player_x;
	int				player_y;
}					t_mappy;

int					ft_count_line_map(char *fichier);
void				initialize_textures(t_mappy *map);
void				select_image(t_mappy *map, int x, int y);
void				ft_hook(void *param);
int					map_is_ber(char *filename);
void				exit_error(char *msg);
int					map_is_rectangle(char **tab_map);
void				aff_map(t_mappy *sex, int fd, char *filename);
char				**tab_map(char *argv);
int					check_map(char *filename, char **tab_map);
int					is_valid(char **map, int x, int y, t_mappy *sex);
void				delete_img_collected(t_mappy *sex);
void				select_key(mlx_key_data_t press, int new_x, int new_y,
						t_mappy *map);
void				free_map(char **tab_map);
void				wall_checker(char **tab);
int					check_path(t_mappy *all);

#endif
