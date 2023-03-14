/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:26:05 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/14 22:49:48 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->info->fork[philo->l_fork_id - 1]);
		display_global(philo, MSF);
		pthread_mutex_lock(&philo->info->fork[philo->r_fork_id - 1]);
		display_global(philo, MSF);
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork[philo->r_fork_id - 1]);
		display_global(philo, MSF);
		pthread_mutex_lock(&philo->info->fork[philo->l_fork_id - 1]);
		display_global(philo, MSF);
	}
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->info->fork[philo->l_fork_id - 1]);
		pthread_mutex_unlock(&philo->info->fork[philo->r_fork_id - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->fork[philo->r_fork_id - 1]);
		pthread_mutex_unlock(&philo->info->fork[philo->l_fork_id - 1]);
	}
}

void	philo_eat(t_philo *philo)
{
	lock_forks(philo);
	display_global(philo, MSE);
	pthread_mutex_lock(&philo->info->lock);
	philo->last_meal = timestamp_ms();
	if (philo->info->n_meals > 0)
		philo->info->meals_eaten++;
	pthread_mutex_unlock(&philo->info->lock);
	usleep(philo->info->t_eat * 1000);
	unlock_forks(philo);
}

void	philo_slt(t_philo *philo)
{
	display_global(philo, MSSL);
	usleep(philo->info->t_sleep * 1000);
	display_global(philo, MST);
}

void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->info->lock);
	while (philo->info->game_over == 0)
	{
		pthread_mutex_unlock(&philo->info->lock);
		philo_eat(philo);
		philo_slt(philo);
		pthread_mutex_lock(&philo->info->lock);
	}
	pthread_mutex_unlock(&philo->info->lock);
	return (NULL);
}
