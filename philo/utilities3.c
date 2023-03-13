/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:13:23 by duzun             #+#    #+#             */
/*   Updated: 2023/03/13 23:41:25 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_chack_av(int ac, char **av)
{
	int	i;
	int	rtn;

	i = 1;
	while (i <= ac - 1)
	{
		rtn = ft_check_number(av[i]);
		if (!rtn)
			return (error_put(rtn));
		i++;
	}
	return (0);
}

int	ft_isin(char c)
{
	int		i;
	char	*charset;

	charset = " \t\v\n\r\f";
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_check_number(const char *s)
{
	int	i;
	int	plussum;
	int	minussum;

	i = -1;
	plussum = 0;
	minussum = 0;
	while (s[++i] != '\0')
	{
		if ((!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+') && !ft_isin(s[i]))
			return (0);
		if (s[i] == '+' || s[i] == '-')
		{
			if (i == 0 || !ft_isdigit(s[i - 1]))
			{
				if (s[i] == '+')
					plussum++;
				else
					minussum++;
			}
			else
				return (0);
		}
	}
	return (!((plussum > 1 || minussum > 1) || (plussum && minussum)));
}
