/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:59:55 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/24 20:20:57 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

char	**tab_map(char *argv)
{
	char	**tab;
	char	*line;
	int		i;
	int		fd;
	int		nb_line;

	i = 0;
	nb_line = ft_count_line_map(argv);
	tab = malloc(sizeof(char *) * (nb_line + 1));
	if (!tab)
		exit_error("Erreur de malloc");
	fd = open(argv, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (i < nb_line)
			line[ft_strlen(line) - 1] = '\0';
		tab[i] = line;
		i++;
	}
	close(fd);
	return (tab);
}
