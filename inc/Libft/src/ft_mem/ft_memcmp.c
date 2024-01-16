/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:43:28 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:43:36 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s11[i] > s22[i])
			return (1);
		else if (s11[i] < s22[i])
			return (-1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char str1[] = "Salut le boss";
	const char str2[] = "Salut le boss";
	const char str3[] = "Salut le pass";
	size_t n = 13;

	int result1 = ft_memcmp(str1, str2, n);
	int result2 = ft_memcmp(str1, str3, n);
	if (result1 == 0)
	{
		printf("str1 et str2 sont identiques.\n");
	}
	else
	{
		printf("str1 et str2 ne sont pas identiques.\n");
	}

	if (result2 == 0)
	{
		printf("str1 et str3 sont identiques.\n");
	}
	else
	{
		printf("str1 et str3 ne sont pas identiques.\n");
	}
	return (0);
}*/
