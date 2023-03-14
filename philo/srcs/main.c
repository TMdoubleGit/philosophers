/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:05:39 by tmichel-          #+#    #+#             */
/*   Updated: 2023/03/14 18:14:08 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	init_struct(ac, av, info);
	init_thread(info);
	return (0);
}
