/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:32:59 by duzun             #+#    #+#             */
/*   Updated: 2023/03/13 15:21:53 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}

int	write_err(char *s)
{
	write(2, "Error: ", 7);
	ft_putstr(s);
	write(2, "\n", 1);
	return (1);
}

int	error_put(int error)
{
	if (error == 1)
		return (write_err("\nEn az bir yanlış argüman\
\nAt least one wrong argument"));
	if (error == 2)
		return (write_err("\nMutex başlatılırken önemli hata\
\nFatal error when intializing mutex"));
	return (1);
}
