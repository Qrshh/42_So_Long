/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:18:53 by abesneux          #+#    #+#             */
/*   Updated: 2023/11/29 14:40:23 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	char source[] = "Coucou le monde";
	char destination[20];

	size_t result = ft_strlcpy(destination, source, sizeof(destination));
	printf("Source : %s\n", source);
	printf("Destination : %s\n", destination);
	printf("Résultat de ft_strlcpy : %zu\n", result);
	return (0);
}*/
