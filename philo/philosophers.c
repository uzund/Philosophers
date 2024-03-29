/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:40:09 by duzun             #+#    #+#             */
/*   Updated: 2023/03/15 05:21:05 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_ft_run(t_main *player, t_game *philos)
{
	int	i;

	i = -1;
	while (++i < player->number_of_philophers)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < player->number_of_philophers)
		pthread_mutex_destroy(&(player->forks[i]));
	pthread_mutex_destroy(&(player->writing));
}

void	death_checker2(t_main *player, t_game *p)
{
	int	i;

	i = -1;
	while (++i < player->number_of_philophers && !(player->dieded))
	{
		pthread_mutex_lock(&(player->check_meal));
		if (time_diff(p[i].t_last_meal, time_stamp()) > player->time_to_die)
		{
			print_status(player, i, "💀 died");
			pthread_mutex_lock(&(player->die_mutex));
			player->dieded = 1;
			pthread_mutex_unlock(&(player->die_mutex));
		}
		pthread_mutex_unlock(&(player->check_meal));
		usleep(100);
	}
}

void	death_checker3(t_main *player, t_game *p)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&(player->ate_mutex));
		if (!(player->nb_eat != -1 && i < player->number_of_philophers && \
			p[i].x_ate + 1 >= player->nb_eat))
		{				
			pthread_mutex_unlock(&(player->ate_mutex));
			break ;
		}
		pthread_mutex_unlock(&(player->ate_mutex));
		i++;
	}
	if (i == player->number_of_philophers)
	{
		pthread_mutex_lock(&(player->ate_mutex));
		player->all_ate = 1;
		pthread_mutex_unlock(&(player->ate_mutex));
	}
}

void	death_checker(t_main *player, t_game *p)
{
	while (1)
	{
		death_checker2(player, p);
		pthread_mutex_lock(&(player->die_mutex));
		if (player->dieded)
		{
			pthread_mutex_unlock(&(player->die_mutex));
			break ;
		}
		pthread_mutex_unlock(&(player->die_mutex));
		death_checker3(player, p);
		pthread_mutex_lock(&(player->ate_mutex));
		if (player->all_ate)
		{
			pthread_mutex_unlock(&(player->ate_mutex));
			break ;
		}
		pthread_mutex_unlock(&(player->ate_mutex));
	}
}

int	ft_run(t_main *player)
{
	int		i;
	t_game	*phi;

	i = 0;
	phi = player->philosophers;
	player->first_time_stamp = time_stamp();
	while (i < player->number_of_philophers)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		pthread_mutex_lock(&(player->check_meal));
		phi[i].t_last_meal = time_stamp();
		pthread_mutex_unlock(&(player->check_meal));
		i++;
	}
	death_checker(player, player->philosophers);
	exit_ft_run(player, phi);
	return (0);
}
