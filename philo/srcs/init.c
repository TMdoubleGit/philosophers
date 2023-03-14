/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:46:21 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/14 18:14:07 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	inf_loop(t_info *info)
{
	while (1)
	{
		if (check_end(info) == 1)
		{
			ft_exit(info);
			break ;
		}
	}
}

void	init_thread_param(t_info *info, int i)
{
	while (i < info->n_philo)
	{
		if (pthread_create(&info->philo[i].th, NULL, thread_routine,
				&info->philo[i]) != 0)
			ft_exit(info);
		i = i + 2;
	}
}

void	init_thread(t_info *info)
{
	int	i;

	info->fork = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!info->fork)
		return ;
	if (pthread_mutex_init(&info->lock, NULL) != 0)
		ft_exit(info);
	i = -1;
	while (++i < info->n_philo)
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			ft_exit(info);
	init_thread_param(info, 1);
	usleep(info->t_eat * 1000);
	init_thread_param(info, 0);
	usleep(info->t_eat * 1000);
	inf_loop(info);
}

void	sub_init_struct(t_info *info)
{
	int	i;

	i = 0;
	while (++i < info->n_philo + 1)
	{
		info->philo[i - 1].id = i;
		info->philo[i - 1].l_fork_id = i;
		info->philo[i - 1].info = info;
		info->philo[i - 1].last_meal = 0;
		if (info->philo[i - 1].id == 1)
			info->philo[i - 1].r_fork_id = info->n_philo;
		else
			info->philo[i - 1].r_fork_id = info->philo[i - 1].id - 1;
	}
}

void	init_struct(int ac, char **av, t_info *info)
{
	if (parse_args(ac, av) == 1)
	{
		info->n_philo = ft_atoi(av[1]);
		info->t_die = ft_atoi(av[2]);
		info->t_eat = ft_atoi(av[3]);
		info->t_sleep = ft_atoi(av[4]);
		info->game_over = 0;
		info->meals_eaten = 0;
		if (ac == 6)
			info->n_meals = ft_atoi(av[5]) * info->n_philo;
		else
			info->n_meals = 0;
		info->philo = malloc(sizeof(t_philo) * info->n_philo);
		if (!info->philo)
			ft_error(MLC);
		sub_init_struct(info);
	}
}
