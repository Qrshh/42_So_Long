/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SOLONG.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:01:57 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/16 22:59:12 by abesneux         ###   ########.fr       */
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

typedef struct s_text_info
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}					TextureInfo;

typedef struct lmp
{
	char			**mapp;
}					lamap;

int					ft_count_line_map(char *fichier);
void				initializeTextures(mlx_t *mlx, TextureInfo *textureArray);
void				select_image(lamap Map, TextureInfo *textureArray, int x,
						int y, mlx_t *mlx);
void				ft_hook(void *param);
void				recupTabMap(TextureInfo *textureArray, lamap MapEnvoi);

#endif