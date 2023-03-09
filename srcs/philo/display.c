/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:34:45 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/09 23:30:04 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	display_timestamp(size_t ts)
{
	size_t	i;

	i = 8 - size_of_timestamp(ts);
	while (i-- > 0)
		printf(".");
	printf("%d", timestamp_ms());
}

void	display_action(t_philo *philo, char *act)
{
	if (!ft_strncmp(act, MSE, ft_strlen(act)))
		printf("%s", MSE);
	else if (!ft_strncmp(act, MSF, ft_strlen(act)))
		printf("%s", MSF);
	else if (!ft_strncmp(act, MST, ft_strlen(act)))
		printf("%s", MST);
	else if (!ft_strncmp(act, MSSL, ft_strlen(act)))
		printf("%s", MSSL);
	else if (!ft_strncmp(act, MSD, ft_strlen(act)))
	{
		printf("%s", MSD);
		ft_exit(philo->info);
		exit (1);
	}
}

void	display_global(t_philo *philo, char *act)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->message);
	display_timestamp(timestamp_ms());
	printf("\t%d\t", philo->id);
	display_action(philo, act);
	pthread_mutex_unlock(&info->message);
}
