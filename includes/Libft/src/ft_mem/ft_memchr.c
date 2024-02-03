/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:55:34 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:43:33 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	target;
	unsigned char	*str;

	target = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == target)
			return (str + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *haystack = "Hello, World!";
	int needle = 'W';

	printf("Searching for '%c' in the string: \"%s\"\n", needle, haystack);

	void *result = ft_memchr(haystack, needle, ft_strlen(haystack));

	if (result)
	{
		printf("Found '%c' at position: %ld\n", needle, (char *)result
			- haystack);
	}
	else
	{
		printf("'%c' not found in the string.\n", needle);
	}

	return (0);
}*/
