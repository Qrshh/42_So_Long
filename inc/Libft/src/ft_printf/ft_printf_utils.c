/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:04:59 by abesneux          #+#    #+#             */
/*   Updated: 2023/11/29 14:39:37 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i])
		len += ft_putchar(str[i]);
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		len += ft_putstr("-2147483648");
	else if (n == INT_MAX)
		len += ft_putstr("2147483647");
	else
	{
		if (n < 0)
		{
			len += ft_putchar('-');
			n = -n;
		}
		if (n > 9)
			len += ft_putnbr(n / 10);
		len += ft_putchar((n % 10) + '0');
	}
	return (len);
}

int	ft_putnbr_un(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_un(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
