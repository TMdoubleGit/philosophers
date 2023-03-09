/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:26:05 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/09 23:30:13 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->l_fork_id - 1]);
	display_global(philo, MSF);
	pthread_mutex_lock(&philo->info->fork[philo->r_fork_id - 1]);
	display_global(philo, MSF);
	display_global(philo, MSE);
	pthread_mutex_lock(&philo->info->meals);
	philo->last_meal = timestamp_ms();
	pthread_mutex_unlock(&philo->info->meals);
	usleep(philo->info->t_eat * 1000);
	pthread_mutex_lock(&philo->info->meals);
	if (philo->info->n_meals > 0)
		philo->info->meals_eaten++;
	pthread_mutex_unlock(&philo->info->meals);
	pthread_mutex_unlock(&philo->info->fork[philo->l_fork_id - 1]);
	pthread_mutex_unlock(&philo->info->fork[philo->r_fork_id - 1]);
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
	while (philo->info->game_over == 0)
	{
		if (philo->info->n_philo % 2 == 0)
			routine_even(philo);
		else
			routine_odd(philo);
	}
	return (NULL);
}

void	routine_even(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		philo_eat(philo);
		philo_slt(philo);
	}
	else if (philo->id % 2 == 1)
	{
		usleep(philo->info->t_eat * 1000);
		philo_eat(philo);
		philo_slt(philo);
	}
}

void	routine_odd(t_philo *philo)
{
	if (philo->id == 1)
	{
		philo_eat(philo);
		philo_slt(philo);
	}
	else if (philo->id % 2 == 0)
	{
		usleep(philo->info->t_eat * 1000);
		philo_eat(philo);
		philo_slt(philo);
	}
	else if (philo->id %2 == 1 && philo->id != 1)
	{
		usleep(philo->info->t_eat * 2000);
		philo_eat(philo);
		philo_slt(philo);
	}
}
