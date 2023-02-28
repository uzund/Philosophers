/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:47:01 by duzun             #+#    #+#             */
/*   Updated: 2023/02/21 23:47:08 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	dst = ft_strncpy(dst, s, len);
	return (dst);
}
