/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:18:22 by nsion             #+#    #+#             */
/*   Updated: 2023/11/13 14:04:01 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printer(int id, char *message, t_socrate *philo)
{
	pthread_mutex_lock(&philo->pesto->write);
	if (philo->pesto->alive == 0)
	{
		pthread_mutex_unlock(&philo->pesto->write);
		return ;
	}
	if (message[0] == 'd')
		philo->pesto->alive = 0;
	printf("%ld %d %s.\n", get_time() - philo->pesto->start, id + 1, message);
	pthread_mutex_unlock(&philo->pesto->write);
}

void	ph_usleep(int wait)
{
	time_t	start_function;

	start_function = get_time();
	while (get_time() - start_function < wait)
		continue ;
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((time_t)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ph_atoi(char *str)
{
	long	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + (*str++ - 48);
	if (*str || nb > INT_MAX)
		return (0);
	return (nb);
}
