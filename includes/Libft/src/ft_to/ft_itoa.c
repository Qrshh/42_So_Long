/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:58 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:45:02 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_nb(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	nb;

	i = count_nb(n) - 1;
	nb = n;
	res = malloc(sizeof(char) * (count_nb(n) + 1));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb != 0)
	{
		res[i] = (nb % 10) + '0';
		i--;
		nb /= 10;
	}
	res[count_nb(n)] = '\0';
	return (res);
}
/*
int	main(void)
{
	int	i;

	i = 356;
	printf("%s", ft_itoa(i));
	return (0);
}*/
