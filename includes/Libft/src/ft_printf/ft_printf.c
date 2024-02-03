/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:42:47 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:43:53 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_nbrbase(unsigned long nbr, char *base, bool ptr)
{
	unsigned long	size;
	unsigned long	nb;
	int				len;

	len = 0;
	nb = nbr;
	if (ptr)
	{
		if (nbr == 0)
			return (len += ft_putstr("(nil)"));
		len += ft_putstr("0x");
		ptr = 0;
	}
	size = ft_strlen_gnl(base);
	if (nb > size - 1)
	{
		len += ft_nbrbase(nb / size, base, ptr);
	}
	len += ft_putchar(base[nb % size]);
	return (len);
}

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_nbrbase(va_arg(args, unsigned long), "0123456789abcdef",
				true);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_un(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789abcdef",
				false);
	else if (format == 'X')
		len += ft_nbrbase(va_arg(args, unsigned int), "0123456789ABCDEF",
				false);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(arguments, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			len += ft_format(arguments, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
	}
	va_end(arguments);
	return (len);
}
