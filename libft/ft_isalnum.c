/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:07:27 by duzun             #+#    #+#             */
/*   Updated: 2022/11/25 23:02:54 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// Bu fonksiyon ile c değişkenine verilen değer alfanumerik ise 1 değilse 0
// döndürür.

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') \
		|| (c >= 'a' && c <= 'z'));
}
/*
int	main(void)
{
	int	x;

	x = 50;
	printf("değer alfanumerik değer ise 1 yazar değilse 0 yazar : %d\n", \
	ft_isalnum(x));
	return (0);
}
*/
