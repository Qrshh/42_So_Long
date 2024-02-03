/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:06:18 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:43:43 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = destination;
	src = source;
	i = 0;
	if (src > dest)
	{
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (src < dest)
	{
		while (size != 0)
		{
			size--;
			dest[size] = src[size];
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void) {
	char source[] = "This is a test.";
	char destination[20];

	ft_memmove(destination, source, 14);

	printf("destination : %s", destination);
	return (0);
}*/
