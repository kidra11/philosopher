/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:07:49 by nsion             #+#    #+#             */
/*   Updated: 2023/11/13 14:04:58 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isalive(t_socrate *philo)
{
	if (get_time() - philo->last_eat >= philo->pesto->t_dead)
	{
		printer(philo->id, "died", philo);
		return (0);
	}
	return (1);
}

void	thinking(t_socrate *philo)
{
	printer(philo->id, "is thinking", philo);
}

void	sleeping(t_socrate *philo)
{
	printer(philo->id, "is sleeping", philo);
	ph_usleep(philo->pesto->t_sleep);
}

void	eating(t_socrate *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->pesto->forks[philo->rightfork]);
		pthread_mutex_lock(&philo->pesto->forks[philo->leftfork]);
	}
	else
	{
		pthread_mutex_lock(&philo->pesto->forks[philo->leftfork]);
		pthread_mutex_lock(&philo->pesto->forks[philo->rightfork]);
	}
	printer(philo->id, "has taken a fork", philo);
	printer(philo->id, "has taken a fork", philo);
	printer(philo->id, "is eating", philo);
	philo->last_eat = get_time();
	if (philo->meals != -1)
		philo->meals--;
	ph_usleep(philo->pesto->t_eat);
	pthread_mutex_unlock(&philo->pesto->forks[philo->rightfork]);
	pthread_mutex_unlock(&philo->pesto->forks[philo->leftfork]);
}

// routine des philo:
void	*routine(void *pesto)
{
	t_socrate	*philo;

	philo = (t_socrate *)pesto;
	while (philo->meals != 0)
	{
		if (isalive(philo) == 0)
			return (NULL);
		eating(philo);
		if (isalive(philo) == 0)
			return (NULL);
		sleeping(philo);
		if (isalive(philo) == 0)
			return (NULL);
		thinking(philo);
	}
	return (NULL);
}
