/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:48:13 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:43:28 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char tab[] = "Salut";
	size_t len = sizeof(tab) - 1;
	printf("Avant ft_bzero : %s\n", tab);
	ft_bzero(tab, len);
	printf("Après ft_bzero : %s\n", tab);
	return (0);
}*/
