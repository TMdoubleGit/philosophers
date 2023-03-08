/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:30:27 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/08 11:55:18 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (*(s + i))
	{
		write(fd, &*(s + i), 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 == s2)
		return (0);
	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < n)
		i++;
	if (i == n)
		return (0);
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}
