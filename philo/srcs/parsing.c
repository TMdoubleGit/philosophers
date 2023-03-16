/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:33:44 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/16 17:03:34 by tmichel-         ###   ########.fr       */
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
	if (ac < 5)
		ft_error(NUMB_ARG);
	if (ac > 6)
		ft_error(NUMB_ARG);
	ft_number(ac, av);
	if (ft_atoi(av[1]) <= 0)
		ft_error(T_PHILO);
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		ft_error(T_ACTION);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		ft_error(T_MEALS);
	return (1);
}
