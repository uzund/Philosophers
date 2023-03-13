/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:35:01 by duzun             #+#    #+#             */
/*   Updated: 2023/03/13 14:03:19 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_main *player)
{
	int i;

	i = player->number_of_philophers;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(player->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(player->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(player->check_meal), NULL))
		return (1);
	return (0);
}

int	init_philosophers(t_main *player)
{
	int i;

	i = player->number_of_philophers;
	while (--i >= 0)
	{
		player->philosophers[i].id = i;
		player->philosophers[i].x_ate = 0;
		player->philosophers[i].left_fork_id = i;
		player->philosophers[i].right_fork_id = (i + 1) % player->number_of_philophers;
		player->philosophers[i].t_last_meal = 0;
		player->philosophers[i].player = player;
	}
	return (0);
}

int	init_all(t_main *player, char **av)
{
	player->number_of_philophers = ft_atoi(av[1]);
	player->time_to_die = ft_atoi(av[2]);
	player->time_to_eat = ft_atoi(av[3]);
	player->time_to_sleep = ft_atoi(av[4]);
	player->all_ate = 0;
	player->dieded = 0;
	if (player->number_of_philophers < 2 || player->time_to_die < 0 || player->time_to_eat < 0
		|| player->time_to_sleep < 0 || player->number_of_philophers > 250)
		return (1);
	if (av[5])
	{
		player->nb_eat = ft_atoi(av[5]);
		if (player->nb_eat <= 0)
			return (1);
	}
	else
		player->nb_eat = -1;
	if (init_mutex(player))
		return (2);
	init_philosophers(player);
	return (0);
}

int		main(int ac, char **av)
{
	t_main	player;
	int		ret;

	if (ac != 5 && ac != 6)
		return (write_err("Wrong amount of arguments"));
	if ((ret = init_all(&player, av)))
		return (error_put(ret));
	if (launcher(&player))
		return (write_err("There was an error creating the threads"));
	return (0);
}