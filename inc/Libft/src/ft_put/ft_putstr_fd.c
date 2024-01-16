/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:11:56 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:44:06 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
int	main(void)
{
	char *message = "Bonjour, le monde!";
	int fd = open("test", O_WRONLY | O_CREAT);
		// Utilisez 1 pour la sortie standard (stdout)

	ft_putstr_fd(message, fd);
	close (fd);
	return (0);
}*/
