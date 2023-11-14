/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:43:23 by nsion             #+#    #+#             */
/*   Updated: 2023/11/13 14:01:22 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	starting(t_pasta *pesto)
{
	int	i;

	i = -1;
	while (++i < pesto->nb_philo)
		pthread_mutex_init(&pesto->forks[i], NULL);
	pthread_mutex_init(&pesto->write, NULL);
	i = -1;
	while (++i < pesto->nb_philo)
	{
		if (pthread_create(&pesto->philo[i].id_thread, NULL, routine,
				&pesto->philo[i]))
			return (ft_printf("ERROR : thread creation.\n"));
	}
	i = -1;
	while (++i < pesto->nb_philo)
	{
		if (pthread_join(pesto->philo[i].id_thread, NULL))
			return (ft_printf("ERROR : waiting thread.\n"));
	}
	i = -1;
	while (++i < pesto->nb_philo)
		pthread_mutex_destroy(&pesto->forks[i]);
	pthread_mutex_destroy(&pesto->write);
	return (0);
}

int	init_philo(t_pasta *pasta)
{
	int	i;

	i = 0;
	while (i < pasta->nb_philo)
	{
		pasta->philo[i].meals = pasta->nb_meals;
		pasta->philo[i].id = i;
		pasta->philo[i].pesto = pasta;
		pasta->philo[i].last_eat = pasta->start;
		pasta->philo[i].leftfork = i;
		pasta->philo[i].rightfork = (i + 1) % pasta->nb_philo;
		i++;
	}
	return (1);
}

int	construct_struct(int num, char **str, t_pasta *pasta)
{
	pasta->nb_philo = ph_atoi(str[1]);
	pasta->t_dead = ph_atoi(str[2]);
	pasta->t_eat = ph_atoi(str[3]);
	pasta->t_sleep = ph_atoi(str[4]);
	pasta->alive = 1;
	pasta->nb_meals = -1;
	if (num == 6)
		pasta->nb_meals = ph_atoi(str[5]);
	if (!pasta->nb_philo || !pasta->t_dead || !pasta->t_eat
		|| !pasta->t_sleep || !pasta->nb_meals
		|| pasta->nb_philo > 1024)
		return (0);
	pasta->start = get_time();
	return (init_philo(pasta));
}

int	check_argv(int num, char **str, t_pasta *pasta)
{
	int	i;
	int	o;

	o = 1;
	while (o < num)
	{
		i = 0;
		while (str[o][i])
		{
			if (str[o][i] < '0' || str[o][i] > '9')
				return (0);
			i++;
		}
		o++;
	}
	return (construct_struct(num, str, pasta));
}

int	main(int ac, char **av)
{
	t_pasta	pasta;

	if (ac < 5 || ac > 6)
		return (ft_printf("ERROR : number of arguments.\n"));
	if (!check_argv(ac, av, &pasta))
		return (ft_printf("ERROR : non valid argument(s).\n"));
	if (pasta.nb_philo == 1)
	{
		ft_printf("0 1 has taken a fork\n");
		ft_printf("%d 1 died\n", pasta.t_dead);
		return (0);
	}
	starting(&pasta);
	return (0);
}
