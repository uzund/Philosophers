/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:40:09 by duzun             #+#    #+#             */
/*   Updated: 2023/03/13 15:37:24 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	(philo->x_ate)++;
	pthread_mutex_unlock(&(player->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(player->forks[philo->right_fork_id]));
}

void	*p_thread(void *void_philosopher)
{
	int		i;
	t_game	*philo;
	t_main	*player;

	i = 0;
	philo = (t_game *)void_philosopher;
	player = philo->player;
	if (philo->id % 2)
		usleep(15000);
	while (!(player->dieded))
	{
		philo_eats(philo);
		if (player->all_ate)
			break ;
		print_status(player, philo->id, "💤  is sleeping");
		smart_sleep(player->time_to_sleep, player);
		print_status(player, philo->id, "💭 is thinking");
		i++;
	}
	return (NULL);
}

void	exit_launcher(t_main *player, t_game *philos)
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
				r->dieded = 1;
			}
			pthread_mutex_unlock(&(r->check_meal));
			usleep(100);
		}
		if (r->dieded)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->number_of_philophers && \
			p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->number_of_philophers)
			r->all_ate = 1;
	}
}

int	launcher(t_main *player)
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
		phi[i].t_last_meal = time_stamp();
		i++;
	}
	death_checker(player, player->philosophers);
	exit_launcher(player, phi);
	return (0);
}
