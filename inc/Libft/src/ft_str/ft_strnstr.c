/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:09:32 by abesneux          #+#    #+#             */
/*   Updated: 2023/11/29 14:40:40 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;
	char	*a;

	a = (char *)big;
	little_len = 0;
	while (little[little_len])
		little_len++;
	if (little_len == 0)
		return (a);
	i = 0;
	while (a[i] && i < len)
	{
		j = 0;
		while (a[i + j] && little[j] && a[i + j] == little[j] && i + j < len)
			j++;
		if (j == little_len)
		{
			return (a + i);
		}
		i++;
	}
	return (NULL);
}
/*
int main() {
    const char *haystack = "Hello";
    const char *needle = "World";
    size_t len = 13;  // Limite la recherche à une partie de la chaîne.

    char *result = ft_strnstr(haystack, needle, len);

    if (result) {
        printf("Chaine trouvee : %s\n", result);
    } else {
        printf("Chaine non trouvee.\n");
    }

    return 0;
}*/
