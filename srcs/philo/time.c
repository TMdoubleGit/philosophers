/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:40:02 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/09 23:28:11 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + (tv.tv_usec / 1000));
}

int	timestamp_ms(void)
{
	static int	start = 0;

	if (start == 0)
		start = gettimeofday_ms();
	return (gettimeofday_ms() - start);
}

int	size_of_timestamp(int ts)
{
	int	i;

	i = 1;
	while (ts > 9)
	{
		ts /= 10;
		i++;
	}
	return (i);
}
