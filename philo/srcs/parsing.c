/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:33:44 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/20 14:19:32 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char *err, t_info *info)
{
	ft_putstr_fd(err, 2);
	free(info);
	return (0);
}

int	ft_number(int ac, char **av)
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
			if (ft_isdigit(av[i][j++]) == 1)
				while (av[i][j] == ' ')
					j++;
			else
				return (0);
		}
		j = 0;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_info *info)
{
	if (ac < 5)
		return (ft_error(NUMB_ARG, info));
	if (ac > 6)
		return (ft_error(NUMB_ARG, info));
	if (!ft_number(ac, av))
		return (ft_error(DIGITS, info));
	if (ft_atol(av[1]) <= 0)
		return (ft_error(T_PHILO, info));
	if (ft_atol(av[2]) <= 0 || ft_atol(av[3]) <= 0 || ft_atol(av[4]) <= 0)
		return (ft_error(T_ACTION, info));
	if (ac == 6 && ft_atol(av[5]) <= 0)
		return (ft_error(T_MEALS, info));
	return (1);
}
