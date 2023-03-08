/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:28:26 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/08 23:51:38 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dead_loop(t_info *info, t_philo philo)
{
	usleep(1000);
	display_global(&philo, MSD);
	info->game_over = 1;
	pthread_mutex_unlock(&info->check);
}

void	meal_loop(t_info *info)
{
	usleep(1000);
	pthread_mutex_lock(&info->message);
	printf(MSM);
	pthread_mutex_unlock(&info->message);
	info->game_over = 1;
	pthread_mutex_unlock(&info->check);
}

int	check_end(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_mutex_lock(&info->check);
		if ((timestamp_ms() - info->philo[i].last_meal) > info->t_die)
		{
			dead_loop(info, info->philo[i]);
			return (1);
		}
		else if (info->n_meals == info->meals_eaten && info->n_meals > 0)
		{
			meal_loop(info);
			return (1);
		}
		i++;
		pthread_mutex_unlock(&info->check);
	}
	pthread_mutex_unlock(&info->check);
	return (0);
}

void	ft_exit(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
	{
		pthread_detach(info->philo[i].th);
		pthread_mutex_destroy(&info->fork[i]);
	}
	pthread_mutex_destroy(&info->message);
	pthread_mutex_destroy(&info->check);
	free(info->fork);
	free(info->philo);
	free(info);
	exit(EXIT_SUCCESS);
}
