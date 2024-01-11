/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:53:59 by abesneux          #+#    #+#             */
/*   Updated: 2023/11/29 14:40:52 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
/*
#include <stdio.h>

int	main(void)
{
	const char *input_str = "Exemple de phrase";
	unsigned int start = 8;
	size_t len = 7;

	char *substring = ft_substr(input_str, start, len);

	if (substring)
	{
		printf("Substring: %s\n", substring);
		free(substring);
		// N'oubliez pas de libérer la mémoire allouée dynamiquement.
	}
	else
	{
		printf("Échec de l'allocation mémoire.\n");
	}

	return (0);
}*/
