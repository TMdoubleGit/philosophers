/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:46:21 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/06 15:09:05 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_args(int ac, char **av, t_info *info)
{
	int	i;

	i = -1;
	if (parse_args(ac, av) == 1)
	{
		info->n_philo = ft_atoi(av[1]);
		info->t_die = ft_atoi(av[2]);
		info->t_eat = ft_atoi(av[3]);
		info->t_sleep = ft_atoi(av[4]);
		if (ac == 6)
			info->n_meals = ft_atoi(av[5]);
		info->philo = malloc(sizeof(t_philo) * info->n_philo);
		if (!info->philo)
			ft_error(MLC);
		while (++i < info->n_philo)
		{
			info->philo[i].id = i;
			info->philo[i].l_fork_id = i;
			if (info->philo[i].id == 0)
				info->philo[i].r_fork_id = info->n_philo - 1;
			else
				info->philo[i].r_fork_id = info->philo[i].id - 1;
		}
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_info	info;

	i = -1;
	ft_init_args(ac, av, &info);
	while (i < info.n_philo)
	{
		display_global(&info.philo[i], "sleep");
		i++;
	}
	return (0);
}
