/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:41:04 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/22 23:41:09 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SOLONG.h"

int	check_map(char *filename)
{
	int		i;
	int		j;
	int		filename_len;
	char	*filename_last;

	filename_len = ft_strlen(filename);
	if (filename_len > 4)
	{
		i = filename_len - 4;
		j = 0;
		filename_last = calloc(5, sizeof(char));
		while (filename[i])
		{
			filename_last[j] = filename[i];
			i++;
			j++;
		}
		if (ft_strcmp(filename_last, EXTENSION) == 0)
			return (0);
		free(filename_last);
	}
	return (1);
}
