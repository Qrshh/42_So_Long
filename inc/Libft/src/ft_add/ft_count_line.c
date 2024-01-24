/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:20:59 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/24 20:22:34 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <fcntl.h>

int	ft_count_line(int fd)
{
	int	i;

	if (fd == -1)
	{
		ft_printf("Erreur d'ouverture du fichier");
		return (-1);
	}
	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}
