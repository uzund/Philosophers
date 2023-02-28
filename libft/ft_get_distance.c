/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:37:50 by duzun             #+#    #+#             */
/*   Updated: 2023/02/28 15:41:08 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_distance(t_list **lst, int index)
{
	t_list	*lst_tmp;
	int		distance;

	distance = 0;
	lst_tmp = *lst;
	while (lst)
	{
		if (lst_tmp->index == index)
			break ;
		distance++;
		lst_tmp = lst_tmp->next;
	}
	return (distance);
}
