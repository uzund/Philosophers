/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:03:19 by duzun             #+#    #+#             */
/*   Updated: 2023/03/14 01:30:14 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return (num * sign);
}

long long	time_stamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long passing_time, long long now_time)
{
	return (now_time - passing_time);
}

void	smart_sleep(long long time, t_main *player)
{
	long long	i;

	i = time_stamp();
	while (1)
	{
		pthread_mutex_lock(&(player->die_mutex));
		if (player->dieded)
		{
			pthread_mutex_unlock(&(player->die_mutex));
			break ;
		}
		pthread_mutex_unlock(&(player->die_mutex));
		if (time_diff(i, time_stamp()) >= time)
			break ;
		usleep(50);
	}
}

void	print_status(t_main *player, int id, char *string)
{
	pthread_mutex_lock(&(player->writing));
	pthread_mutex_lock(&(player->die_mutex));
	if (!(player->dieded))
	{
		printf("%lli ", time_stamp() - player->first_time_stamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(player->die_mutex));
	pthread_mutex_unlock(&(player->writing));
	return ;
}
