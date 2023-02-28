/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:50:09 by duzun             #+#    #+#             */
/*   Updated: 2022/11/25 23:11:53 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// Bu fonksiyon bir gösterici *src ile gösterilen hafıza alanından "n" byte'lık 
//veriyi *dest ile gösterilen hafıza alanına taşır.dest göstericisini döndürür

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmpdest;
	const unsigned char	*tmpsrc;

	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	if (!tmpdest && !tmpsrc)
		return (NULL);
	if (tmpsrc < tmpdest)
		ft_memcpy(dest, src, n);
	else
		while (n-- > 0)
			*(tmpdest++) = *(tmpsrc++);
	return (dest);
}

/*
int	main(void)
{
	char str1[] = "Davut UZUN";
	char str2[] = "42 Okul";

	ft_memmove (str2,str1,5);
	printf("str2 değişkenin değeri '42 Okul' iken değişmiş son hali:%s\n",str2);
	return (0);
}
*/
