/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:45:13 by nsion             #+#    #+#             */
/*   Updated: 2023/11/13 13:56:38 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include "ft_printf/libftprintf.h"

# define INT_MAX 2147483647

struct	s_pasta;

typedef struct s_socrate
{
	struct s_pasta	*pesto;
	pthread_t		id_thread;
	time_t			last_eat;
	int				meals;
	int				id;
	int				leftfork;
	int				rightfork;
}		t_socrate;

typedef struct s_pasta
{
	struct s_socrate	philo[1024];
	int					nb_philo;
	int					t_dead;
	int					t_eat;
	int					t_sleep;
	int					nb_meals;
	int					alive;
	pthread_mutex_t		forks[1024];
	time_t				start;
	pthread_mutex_t		write;
}	t_pasta;

// philo.c
int		starting(t_pasta *pesto);

int		init_philo(t_pasta *pasta);

int		construct_struct(int num, char **str, t_pasta *pasta);

int		check_argv(int num, char **str, t_pasta *pasta);

//thread.c
int		isalive(t_socrate *philo);

void	*routine(void *pesto);

void	thinking(t_socrate *philo);

void	sleeping(t_socrate *philo);

void	eating(t_socrate *philo);

//utils.c
void	printer(int id, char *message, t_socrate *philo);

void	ph_usleep(int wait);

time_t	get_time(void);

int		ph_atoi(char *str);

#endif