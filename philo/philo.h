/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duzun <davut@uzun.ist>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:41:04 by duzun             #+#    #+#             */
/*   Updated: 2023/03/14 01:07:44 by duzun            ###   ########.fr       */
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
	pthread_mutex_t		die_mutex;
	pthread_mutex_t		ate_mutex;
	t_game				philosophers[250];
}	t_main;

void					ft_putstr(char *s);
int						ft_chack_av(int ac, char **av);
int						ft_check_number(const char *s);
int						write_err(char *str);
int						error_put(int error);
int						ft_isin(char c);
int						ft_isdigit(int c);
int						init_all(t_main *player, char **av);
int						ft_atoi(const char *str);
void					print_status(t_main *player, int id, char *string);
long long				time_stamp(void);
long long				time_diff(long long passing_time, long long now_time);
void					smart_sleep(long long time, t_main *player);
int						ft_run(t_main *player);
void					exit_ft_run(t_main *player, t_game *philos);
void					death_checker2(t_main *r, t_game *p);
void					death_checker3(t_main *r, t_game *p);
void					*p_thread(void *void_philosopher);
void					philo_eats(t_game *philo);

#endif
