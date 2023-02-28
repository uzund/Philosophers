/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:12:06 by duzun             #+#    #+#             */
/*   Updated: 2023/02/21 23:37:52 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *s)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && ft_isin(s[i]))
			i++;
		if (s[i])
			word++;
		while (s[i] && !ft_isin(s[i]))
			i++;
	}
	return (word);
}
