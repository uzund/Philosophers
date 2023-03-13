/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:40:09 by duzun             #+#    #+#             */
/*   Updated: 2023/03/14 00:38:21 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	philo_eats(t_game *philo)
{
	t_main	*player;

	player = philo->player;
	pthread_mutex_lock(&(player->forks[philo->left_fork_id]));
	print_status(player, philo->id, "🍽  has taken a fork");
	pthread_mutex_lock(&(player->forks[philo->right_fork_id]));
	print_status(player, philo->id, "🍽  has taken a fork");
	pthread_mutex_lock(&(player->check_meal));
	print_status(player, philo->id, "🍕 is eating");
	philo->t_last_meal = time_stamp();
	pthread_mutex_unlock(&(player->check_meal));
	smart_sleep(player->time_to_eat, player);
	pthread_mutex_lock(&(player->ate_mutex));
	(philo->x_ate)++;
	pthread_mutex_unlock(&(player->ate_mutex));
	pthread_mutex_unlock(&(player->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(player->forks[philo->right_fork_id]));
}

void	*p_thread(void *void_philosopher)
{
	t_game	*philo;
	t_main	*player;

	philo = (t_game *)void_philosopher;
	player = philo->player;
	if (philo->id % 2)
		usleep(15000);
	while (1)
	{
		philo_eats(philo);
		if (player->all_ate)
			break ;
		print_status(player, philo->id, "💤  is sleeping");
		smart_sleep(player->time_to_sleep, player);
		print_status(player, philo->id, "💭 is thinking");
		pthread_mutex_lock(&(player->die_mutex));
		if (player->dieded)
		{
			pthread_mutex_unlock(&(player->die_mutex));
			break ;
		}
		pthread_mutex_unlock(&(player->die_mutex));
	}
	return (NULL);
}

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

void	death_checker(t_main *r, t_game *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->number_of_philophers && !(r->dieded))
		{
			pthread_mutex_lock(&(r->check_meal));
			if (time_diff(p[i].t_last_meal, time_stamp()) > r->time_to_die)
			{
				print_status(r, i, "💀 died");
				pthread_mutex_lock(&(r->die_mutex));
				r->dieded = 1;
				pthread_mutex_unlock(&(r->die_mutex));
			}
			pthread_mutex_unlock(&(r->check_meal));
			usleep(100);
		}
		pthread_mutex_lock(&(r->die_mutex));
		if (r->dieded)
		{
			pthread_mutex_unlock(&(r->die_mutex));
			break ;
		}
		pthread_mutex_unlock(&(r->die_mutex));
		i = 0;
		while (1)
		{
			pthread_mutex_lock(&(r->ate_mutex));
			if (!(r->nb_eat != -1 && i < r->number_of_philophers && \
				p[i].x_ate + 1 >= r->nb_eat))
			{				
				pthread_mutex_unlock(&(r->ate_mutex));
				break ;
			}
			pthread_mutex_unlock(&(r->ate_mutex));
		}
		i++;
		if (i == r->number_of_philophers)
			r->all_ate = 1;
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
