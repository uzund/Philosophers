/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:28:27 by duzun             #+#    #+#             */
/*   Updated: 2022/11/25 22:51:52 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *s1 dizgisi içerisinde "n" uzunluğu kadar *s2 arar, bulduğunda *s2 parametre
// dahilinde geri kalanı döndürür.

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*tmps1;
	char		*tmps2;

	if (!*s2)
		return ((char *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			i = n;
			tmps1 = (char *)s1 + 1;
			tmps2 = (char *)s2 + 1;
			while (i-- && *tmps1 && *tmps2 && *tmps2 == *tmps1)
			{
				++tmps1;
				++tmps2;
			}
			if (*tmps2 == '\0')
				return ((char *)s1);
		}
		++s1;
	}
	return (NULL);
}
