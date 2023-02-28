/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:19:22 by duzun             #+#    #+#             */
/*   Updated: 2023/02/28 15:40:11 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_stack(t_list **lst)
{
	t_list	*lst_tmp;
	t_list	*tmp;

	lst_tmp = *lst;
	while (lst)
	{
		tmp = lst_tmp;
		lst_tmp = lst_tmp->next;
		free(tmp);
	}
	free(lst);
}
