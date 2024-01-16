/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:27:53 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:44:27 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (!src)
		return (dlen);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (dlen + i < size - 1 && src[i])
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
/*
int main()
{
	char	destination[20] = "Hello, ";
	char	source[] = "world!";
	size_t	destination_size;
	size_t	result;

	destination_size = sizeof(destination);
	printf("Before ft_strlcat:\n");
	printf("Destination: %s\n", destination);
	printf("Source: %s\n", source);
	result = ft_strlcat(destination, source, destination_size);
	printf("\nAfter ft_strlcat:\n");
	printf("Destination: %s\n", destination);
	printf("Result: %lu\n", result);
	return (0);
}
*/
