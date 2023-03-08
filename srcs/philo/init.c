/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:46:21 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/08 16:08:03 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_thread(t_info *info)
{
	int	i;

	i = -1;
	info->fork = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!info->fork)
		return ;
	if (pthread_mutex_init(&info->message, NULL) != 0)
		ft_exit(info);
	if (pthread_mutex_init(&info->check, NULL) != 0)
		ft_exit(info);
	while (++i < info->n_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			ft_exit(info);
		if (pthread_create(&info->philo[i].th, NULL, thread_routine,
				&info->philo[i]) != 0)
			ft_exit(info);
	}
	usleep(info->t_die * 1000);
	while (1)
	{
		usleep(1000);
		if (check_end(info) == 1)
		{
			ft_exit(info);
			break ;
		}
	}
}

void	ft_init_struct(int ac, char **av, t_info *info)
{
	int	i;

	i = 0;
	if (parse_args(ac, av) == 1)
	{
		info->n_philo = ft_atoi(av[1]);
		info->t_die = ft_atoi(av[2]);
		info->t_eat = ft_atoi(av[3]);
		info->t_sleep = ft_atoi(av[4]);
		info->game_over = 0;
		if (ac == 6)
			info->n_meals = ft_atoi(av[5]) * info->n_philo;
		info->philo = malloc(sizeof(t_philo) * info->n_philo);
		if (!info->philo)
			ft_error(MLC);
		while (++i < info->n_philo + 1)
		{
			info->philo[i - 1].id = i;
			info->philo[i - 1].l_fork_id = i;
			info->philo[i - 1].info = info;
			if (info->philo[i - 1].id == 1)
				info->philo[i - 1].r_fork_id = info->n_philo - 1;
			else
				info->philo[i - 1].r_fork_id = info->philo[i - 1].id - 1;
		}
	}
}

int	main(int ac, char **av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	ft_init_struct(ac, av, info);
	ft_init_thread(info);
	return (0);
}
