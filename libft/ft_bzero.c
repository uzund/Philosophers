/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:47:20 by duzun             #+#    #+#             */
/*   Updated: 2022/11/25 23:02:31 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// Bu fonksiyon ile gösterilen *s hafıza alanının ilk "n" byte'lık kısmına
// NULL '0' (sıfır / NULL) yazılması sağlanır.

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = '\0';
}
/*
int	main(void)
{
	char	str[] = "davut uzun";

	ft_bzero(str, 2);
	// 0 dan farklı bir değer girilirse çıktı alınamaz!!
	printf("str dizisinin son hali: %s\n", str);
	printf("str dizisinin ilk iki karakterine NULL atandığından \
çıktı alınamadı\n");
	// str dizinin '\0' ile değiştirilmeyen 2. elamanını "v" yazdıralım.
	printf("str dizisinin 2. elamını : %c\n", str[2]);
	printf("str[2] yani 2. elamanı değişmediğinden \"v\" ekrana yazıldı.\n");
	return (0);
}
*/