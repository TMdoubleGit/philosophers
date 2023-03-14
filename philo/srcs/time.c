/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:40:02 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/14 18:14:12 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + (tv.tv_usec / 1000));
}

size_t	timestamp_ms(void)
{
	static size_t	start = 0;

	if (start == 0)
		start = gettimeofday_ms();
	return (gettimeofday_ms() - start);
}

size_t	size_of_timestamp(size_t ts)
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
