/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:41:04 by duzun             #+#    #+#             */
/*   Updated: 2023/03/03 00:19:38 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_game
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philosopher_must_eat ;
	int				philosopher_total_ate;
	unsigned long	time;
}	t_game;

typedef struct s_philo
{
	int				ate;
	int				id;
	unsigned long	last_meal;
	t_game			*gms;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
}	t_philo;


#endif