/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:05:33 by duzun             #+#    #+#             */
/*   Updated: 2023/03/14 01:29:10 by duzun            ###   ########.fr       */
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
	pthread_mutex_lock(&(player->ate_mutex));
	(philo->x_ate)++;
	pthread_mutex_unlock(&(player->ate_mutex));
	pthread_mutex_unlock(&(player->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(player->forks[philo->right_fork_id]));
}

void	p_thread2(t_main *player, t_game *philo)
{
	pthread_mutex_unlock(&(player->ate_mutex));
	print_status(player, philo->id, "💤  is sleeping");
	smart_sleep(player->time_to_sleep, player);
	print_status(player, philo->id, "💭 is thinking");
	pthread_mutex_lock(&(player->die_mutex));
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
		pthread_mutex_lock(&(player->ate_mutex));
		if (player->all_ate)
		{
			pthread_mutex_unlock(&(player->ate_mutex));
			break ;
		}
		p_thread2(player, philo);
		if (player->dieded)
		{
			pthread_mutex_unlock(&(player->die_mutex));
			break ;
		}
		pthread_mutex_unlock(&(player->die_mutex));
	}
	return (NULL);
}
