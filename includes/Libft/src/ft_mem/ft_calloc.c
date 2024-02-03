/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:54:38 by abesneux          #+#    #+#             */
/*   Updated: 2024/01/12 18:43:30 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	resultat;
	char	*ret;

	resultat = nmemb * size;
	ret = malloc(resultat);
	if (!ret)
		return (NULL);
	ft_bzero(ret, resultat);
	return (ret);
}
