/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:48:17 by duzun             #+#    #+#             */
/*   Updated: 2023/02/21 23:48:19 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}
