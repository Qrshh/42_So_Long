/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:03:36 by abesneux          #+#    #+#             */
/*   Updated: 2023/11/29 14:40:10 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
void	print_char_with_index(unsigned int index, char *c)
{
	printf("Character at index %u: %c\n", index, *c);
}

int	main(void)
{
	char s[] = "Hello, World!";

	ft_striteri(s, print_char_with_index);

	return (0);
}*/
