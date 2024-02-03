/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:36:36 by abesneux          #+#    #+#             */
/*   Updated: 2024/02/03 01:43:13 by abesneux         ###   ########.fr       */
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
