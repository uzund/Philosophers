/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:20:36 by duzun             #+#    #+#             */
/*   Updated: 2022/11/25 23:03:59 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* bagli listenin elemanini siler ve hafizadaki yerini temizler, ve o elemanin
* ardini da siler ve serbest birakir. son olarak listenin isaretcisini NULL 
*olarak ayarlar.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst || !del)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start->next;
		del(start->content);
		free(start);
		start = tmp;
	}
	*lst = NULL;
}
