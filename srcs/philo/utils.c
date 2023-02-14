/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:33:44 by tmichel-          #+#    #+#             */
/*   Updated: 2023/02/14 18:11:10 by tmichel-         ###   ########.fr       */
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
				ft_error("Parsing error #1\n");
		}
		j = 0;
	}
}

int	parse_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 6)
		ft_error("Parsing error #2\n");
	ft_number(ac, av);
	if (ft_atoi(av[1]) < 2)
		ft_error("Parsing error #3\n");
	if (ft_atoi(av[2]) <= ft_atoi(av[3]) + ft_atoi(av[4]))
		ft_error("Parsing error #4\n");
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0
		|| ft_atoi(av[5]) <= 0)
		ft_error("Parsing error #5\n");
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = parse_args(ac, av);
	printf("parsing result is %d\n", i);
	return (0);
}
