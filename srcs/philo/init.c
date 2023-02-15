/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:33:44 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/15 17:56:11 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(0);
}

void	ft_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		while (av[i][j] != '\0')
		{
			while (av[i][j] == ' ')
				j++;
			if ((av[i][j] == '-' && av[i][j - 1] != '-' && j == 0) ||
				(av[i][j] == '+' && av[i][j - 1] != '+' && j == 0))
				j++;
			if (ft_isdigit(av[i][j]) == 1)
			{
				j++;
				while (av[i][j] == ' ')
					j++;
			}
			else
				ft_error(DIGITS);
		}
		j = 0;
	}
}

int	parse_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 && ac > 6)
		ft_error(NUMB_ARG);
	ft_number(ac, av);
	if (ft_atoi(av[1]) < 2)
		ft_error(ONE_PHILO);
	if (ft_atoi(av[2]) <= ft_atoi(av[3]) + ft_atoi(av[4]))
		ft_error(T_DIE);
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		ft_error(T_ACTION);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		ft_error(T_MEALS);
	return (1);
}

void	ft_init(int ac, char **av, t_info *info)
{
	int	i;

	i = -1;
	if (parse_args(ac, av) == 1)
	{
		info->n_philo = ft_atoi(av[1]);
		info->t_die = ft_atoi(av[2]);
		info->t_eat = ft_atoi(av[3]);
		info->t_sleep = ft_atoi(av[4]);
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
	ft_init(ac, av, &info);
	printf("il y a %d philos\n", info.n_philo);
	//check id attribution for philos and forks
	while (++i < info.n_philo)
		printf("p_id = %d || lf_id = %d || rf_id = %d\n", info.philo[i].id, info.philo[i].l_fork_id, info.philo[i].r_fork_id);
	return (0);
}
