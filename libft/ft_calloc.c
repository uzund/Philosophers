/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:27:05 by duzun             #+#    #+#             */
/*   Updated: 2022/11/25 23:02:46 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count ile belirtilen dizgiler icin size ile belirtilen boyut kadar hafızada
// yer tahsis edilir. Bu hafıza alanı \0 ile doldurulur.
// geriye bu alanın icerigi dondurulur.

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	rtn = malloc(count * size);
	if (rtn == NULL)
		return (NULL);
	ft_bzero(rtn, count * size);
	return (rtn);
}
