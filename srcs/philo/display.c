/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:34:45 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/06 15:09:05 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	display_timestamp(size_t ts)
{
	size_t	i;

	i = 8 - size_of_timestamp(ts);
	while (i-- > 0)
		printf(".");
	printf("%lu\n", timestamp_ms());
}

void	display_action(char *act)
{
	if (act == "eat")
		printf("is eating 🍜\n");
	else if (act == "think")
		printf("is thinking 🤔\n");
	else if (act == "sleep")
		printf("is sleeping 😴\n");
	else
	{
		printf("is dead 🪦\n");
		//penser a tout free
		exit (1);
	}
}

void	display_global(t_philo philo, char *act)
{
	if (philo.meals_eaten == philo.n_meals)
	{
		display_timestamp(timestamp_ms());
		printf("\tphilosophers have eaten all their meals!\n");
	}
	else
	{
		display_timestamp(timestamp_ms());
		printf("\tPhilosopher %d\t", philo.id);
		display_action(act);
	}
}
