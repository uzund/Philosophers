/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:41:04 by duzun             #+#    #+#             */
/*   Updated: 2023/03/13 14:24:07 by duzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_main;

typedef struct s_game
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_main		*player;
	pthread_t			thread_id;
}	t_game;

typedef struct s_main
{
	int					number_of_philophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long long			first_time_stamp;
	pthread_mutex_t		check_meal;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_game				philosophers[250];
}	t_main;

void					ft_putstr(char *s);
int						write_err(char *str);
int						error_put(int error);
int						init_all(t_main *player, char **av);
int						ft_atoi(const char *str);
void					print_status(t_main *player, int id, char *string);
long long				time_stamp(void);
long long				time_diff(long long passing_time, long long now_time);
void					smart_sleep(long long time, t_main *player);
int						launcher(t_main *player);
void					exit_launcher(t_main *player, t_game *philos);

#endif
