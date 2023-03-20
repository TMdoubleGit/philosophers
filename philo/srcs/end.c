/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:28:26 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/20 13:15:25 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dead_loop(t_info *info, t_philo philo)
{
	info->game_over = 1;
	display_timestamp(timestamp_ms());
	printf("\t%d\t%s", philo.id, MSD);
	pthread_mutex_unlock(&info->lock);
}

void	meal_loop(t_info *info)
{
	info->game_over = 1;
	printf("The feast is over, total nb of meals : %d\n", info->meals_eaten);
	pthread_mutex_unlock(&info->lock);
}

int	check_end(t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&info->lock);
	while (++i < info->n_philo)
	{
		if ((timestamp_ms() - info->philo[i].last_meal) > info->t_die)
			return (dead_loop(info, info->philo[i]), 1);
		else if (info->n_meals > 0 && info->n_meals <= info->meals_eaten)
		{
			meal_loop(info);
			return (1);
		}
	}
	pthread_mutex_unlock(&info->lock);
	return (0);
}

int	ft_exit(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
	{
		pthread_join(info->philo[i].th, NULL);
	}
	i = -1;
	while (++i < info->n_philo)
	{
		pthread_mutex_destroy(&info->fork[i]);
	}
	pthread_mutex_destroy(&info->lock);
	free(info->fork);
	free(info->philo);
	free(info);
	return (1);
}
